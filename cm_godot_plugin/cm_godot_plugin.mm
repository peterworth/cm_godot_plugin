//
//  cm_godot_plugin.m
//  cm_godot_plugin
//
//  Created by admin on 25/11/2024.
//

#import <Foundation/Foundation.h>

#import "cm_godot_plugin.h"

#import "cm_godot_plugin_implementation.h"
#import "core/config/engine.h"
CmGodotPlugin *plugin;

void cm_godot_plugin_init(void) {
    NSLog(@"init plugin");

    plugin = memnew(CmGodotPlugin);
    Engine::get_singleton()->add_singleton(Engine::Singleton("CmGodotPlugin", plugin));
}

void cm_godot_plugin_deinit(void) {
    NSLog(@"deinit plugin");
    
    if (plugin) {
       memdelete(plugin);
   }
}
