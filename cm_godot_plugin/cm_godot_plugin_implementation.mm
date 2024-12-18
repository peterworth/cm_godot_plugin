
#import <Foundation/Foundation.h>

#include "core/config/project_settings.h"
#include "core/object/class_db.h"

#import "cm_godot_plugin_implementation.h"
#import "cm_godot_plugin-Swift.h"

// Type conversions CPP<->ObjC

Variant nsobject_to_variant(NSObject *object);
NSObject *variant_to_nsobject(Variant v);

NSString* to_nsstring(String str) {
    return [[NSString alloc] initWithUTF8String:str.utf8().get_data()];
}

String from_nsstring(NSString* str) {
    const char *s = [str UTF8String];
    return String::utf8(s != NULL ? s : "");
}

NSArray* to_nsarray(Array arr) {
    NSMutableArray *result = [[NSMutableArray alloc] init];
    for (int i = 0; i < arr.size(); ++i) {
        NSObject *value = variant_to_nsobject(arr[i]);
        if (value != NULL) {
            [result addObject:value];
        } else {
            WARN_PRINT("Trying to add something unsupported to the array.");
        }
    }
    return result;
}

Array from_nsarray(NSArray* array) {
    Array result;
    for (NSUInteger i = 0; i < [array count]; ++i) {
        NSObject *value = [array objectAtIndex:i];
        result.push_back(nsobject_to_variant(value));
    }
    return result;
}

NSDictionary* to_nsdictionary(Dictionary dic) {
    NSMutableDictionary *result = [[NSMutableDictionary alloc] init];
    Array keys = dic.keys();
    for (int i = 0; i < keys.size(); ++i) {
        NSString *key = [[NSString alloc] initWithUTF8String:((String)(keys[i])).utf8().get_data()];
        NSObject *value = variant_to_nsobject(dic[keys[i]]);

        if (key == NULL || value == NULL) {
            return NULL;
        }

        [result setObject:value forKey:key];
    }
    return result;
}

Dictionary from_nsdictionary(NSDictionary* dic) {
    Dictionary result;

    NSArray *keys = [dic allKeys];
    long count = [keys count];
    for (int i = 0; i < count; ++i) {
        NSObject *k = [keys objectAtIndex:i];
        NSObject *v = [dic objectForKey:k];

        result[nsobject_to_variant(k)] = nsobject_to_variant(v);
    }
    return result;
}

//convert from apple's abstract type to godot's abstract type....
Variant nsobject_to_variant(NSObject *object) {
    if ([object isKindOfClass:[NSString class]]) {
        return from_nsstring((NSString *)object);
    } else if ([object isKindOfClass:[NSArray class]]) {
        return from_nsarray((NSArray *)object);
    } else if ([object isKindOfClass:[NSDictionary class]]) {
        return from_nsdictionary((NSDictionary *)object);
    } else if ([object isKindOfClass:[NSNumber class]]) {
        //Every type except numbers can reliably identify its type.  The following is comparing to the *internal* representation, which isn't guaranteed to match the type that was used to create it, and is not advised, particularly when dealing with potential platform differences (ie, 32/64 bit)
        //To avoid errors, we'll cast as broadly as possible, and only return int or float.
        //bool, char, int, uint, longlong -> int
        //float, double -> float
        NSNumber *num = (NSNumber *)object;
        if (strcmp([num objCType], @encode(BOOL)) == 0) {
            return Variant((int)[num boolValue]);
        } else if (strcmp([num objCType], @encode(char)) == 0) {
            return Variant((int)[num charValue]);
        } else if (strcmp([num objCType], @encode(int)) == 0) {
            return Variant([num intValue]);
        } else if (strcmp([num objCType], @encode(unsigned int)) == 0) {
            return Variant((int)[num unsignedIntValue]);
        } else if (strcmp([num objCType], @encode(long long)) == 0) {
            return Variant((int)[num longValue]);
        } else if (strcmp([num objCType], @encode(float)) == 0) {
            return Variant([num floatValue]);
        } else if (strcmp([num objCType], @encode(double)) == 0) {
            return Variant((float)[num doubleValue]);
        } else {
            return Variant();
        }
    } else if ([object isKindOfClass:[NSDate class]]) {
        //this is a type that icloud supports...but how did you submit it in the first place?
        //I guess this is a type that *might* show up, if you were, say, trying to make your game
        //compatible with existing cloud data written by another engine's version of your game
        WARN_PRINT("NSDate unsupported, returning null Variant");
        return Variant();
    } else if ([object isKindOfClass:[NSNull class]] or object == nil) {
        return Variant();
    } else {
        WARN_PRINT("Trying to convert unknown NSObject type to Variant");
        return Variant();
    }
}

NSObject *variant_to_nsobject(Variant v) {
    if (v.get_type() == Variant::STRING) {
        return to_nsstring((String)v);
    } else if (v.get_type() == Variant::FLOAT) {
        return [NSNumber numberWithDouble:(double)v];
    } else if (v.get_type() == Variant::INT) {
        return [NSNumber numberWithLongLong:(long)(int)v];
    } else if (v.get_type() == Variant::BOOL) {
        return [NSNumber numberWithBool:BOOL((bool)v)];
    } else if (v.get_type() == Variant::DICTIONARY) {
        return to_nsdictionary(v);
    } else if (v.get_type() == Variant::ARRAY) {
        return to_nsarray(v);
    }
    WARN_PRINT(String("Could not add unsupported type to iCloud: '" + Variant::get_type_name(v.get_type()) + "'").utf8().get_data());
    return NULL;
}


// Plugin functions

CmGodotPlugin::CmGodotPlugin() {
    NSLog(@"initialize plugin");
    
    players = [[NSMutableArray alloc] init];
    
    supportsHaptics = CHHapticEngine.capabilitiesForHardware.supportsHaptics;
    NSLog(@"haptics supported?: %@", supportsHaptics ? @"yes" : @"no");
    
    if (supportsHaptics) {
        NSError* error;
        engine = [[CHHapticEngine alloc] initAndReturnError:&error];
        error ? NSLog(@"haptics create engine error: %@",error.localizedDescription):NSLog(@"haptics engine created");
    }
}

CmGodotPlugin::~CmGodotPlugin() {
    NSLog(@"deinitialize plugin");
}

void CmGodotPlugin::_bind_methods() {
    ClassDB::bind_method(D_METHOD("hello"), &CmGodotPlugin::hello);
    
    ClassDB::bind_method(D_METHOD("haptics_make_player"), &CmGodotPlugin::haptics_make_player);
    ClassDB::bind_method(D_METHOD("haptics_buzz"), &CmGodotPlugin::haptics_buzz);
}

String CmGodotPlugin::hello() {
    return from_nsstring([SwiftClass hello]);
}

void CmGodotPlugin::haptics_make_player(float duration, float intensity, float sharpness) {
    NSDictionary* hapticDict = @{ CHHapticPatternKeyPattern: @[@{ CHHapticPatternKeyEvent: @{
        CHHapticPatternKeyEventType: CHHapticEventTypeHapticContinuous,
        CHHapticPatternKeyTime: @(CHHapticTimeImmediate),
        CHHapticPatternKeyEventDuration: @(duration),
        CHHapticPatternKeyEventParameters : @[@{
            CHHapticPatternKeyParameterID : @("HapticIntensity"),
            CHHapticPatternKeyParameterValue : @(intensity)
        },@{
            CHHapticPatternKeyParameterID : @("HapticSharpness"),
            CHHapticPatternKeyParameterValue : @(sharpness)
        }]
    }}]};
    NSError* patternError;
    CHHapticPattern* pattern = [[CHHapticPattern alloc] initWithDictionary:hapticDict error:&patternError];
    patternError ? NSLog(@"haptics create pattern error: %@",patternError.localizedDescription):NSLog(@"haptics pattern created");
    NSError* playerError = nil;
    id<CHHapticPatternPlayer> player = [engine createPlayerWithPattern:pattern error:&playerError];
    playerError ? NSLog(@"haptics create player error: %@",playerError.localizedDescription):NSLog(@"haptics player created");
    [players addObject:player];
}

void CmGodotPlugin::haptics_buzz(int playerIndex) {
    
    id<CHHapticPatternPlayer> player = players[playerIndex];
    if (supportsHaptics && player != NULL) {

    [engine startWithCompletionHandler:^(NSError* returnedError) {
        [engine notifyWhenPlayersFinished:^CHHapticEngineFinishedAction(NSError * _Nullable error) {
            //NSLog(@"stopping engine");
            return CHHapticEngineFinishedActionStopEngine;
        }];
        NSError* error;
        [player startAtTime:0 error:&error];
        //error ? NSLog(@"haptics play error: %@",error.localizedDescription):NSLog(@"haptics started engine and played");
    }];
        
    }
}
