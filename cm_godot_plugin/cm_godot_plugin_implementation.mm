
#import <Foundation/Foundation.h>

#include "core/config/project_settings.h"
#include "core/object/class_db.h"

#import "cm_godot_plugin_implementation.h"

void CmGodotPlugin::_bind_methods() {
    ClassDB::bind_method(D_METHOD("foo"), &CmGodotPlugin::foo);
}

Error CmGodotPlugin::foo() {
    NSLog(@"foo");
    return OK;
}

CmGodotPlugin::CmGodotPlugin() {
    NSLog(@"initialize object");
}

CmGodotPlugin::~CmGodotPlugin() {
    NSLog(@"deinitialize object");
}
