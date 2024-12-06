
#ifndef cm_godot_plugin_implementation_h
#define cm_godot_plugin_implementation_h

#include "core/object/object.h"
#include "core/object/class_db.h"

class CmGodotPlugin : public Object {
    GDCLASS(CmGodotPlugin, Object);
    
    static void _bind_methods();
    
public:
    
    Error foo();
    
    CmGodotPlugin();
    ~CmGodotPlugin();
};

#endif
