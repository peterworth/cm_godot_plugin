
#ifndef cm_godot_plugin_implementation_h
#define cm_godot_plugin_implementation_h

#include "core/object/object.h"
#include "core/object/class_db.h"

#import <CoreHaptics/CoreHaptics.h>

class CmGodotPlugin : public Object {
    GDCLASS(CmGodotPlugin, Object);
    
    static void _bind_methods();
    
    BOOL supportsHaptics;
    CHHapticEngine* engine;
    NSMutableArray* players;
    
public:
    
    CmGodotPlugin();
    ~CmGodotPlugin();
    
    String hello();
    
    void haptics_make_player(float duration, float intensity, float sharpness);
    void haptics_buzz(int playerIndex);
};

#endif
