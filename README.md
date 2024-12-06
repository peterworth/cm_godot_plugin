# cm_godot_plugin
template for ios godot plugin

this guide has some useful bits but it didn't work for me:

https://docs.godotengine.org/en/stable/tutorials/platform/ios/ios_plugin.html

so i broke down the process into smaller steps

how to make a godot ios plugin step by step:

xcode -> new project, ios static library

choose objective-c

call it whatever name. lowercase and underscores is best. one word lowercase is nicest.

check it builds, should be fine

copy the code for the .m and .h files from cm_godot_plugin

and change any cm_godot_plugin or CmGodotPlugin to the right name

but, comment out most lines in the .m file so that only this remains:

#import <Foundation/Foundation.h>

#import "cm_godot_plugin.h"

void godot_plugin_init(void) {

    NSLog(@"init plugin");

}

void godot_plugin_deinit(void) {

    NSLog(@"deinit plugin");

}

then it should still build fine

copy the SConstruct file from cm_godot_plugin

and change any cm_godot_plugin to right name

make a /bin/ folder in the project dir

then try building in terminal with:

scons target=release arch=arm64 plugin=[your plugin name] version=4.0

(install scons first obviously)

should build fine and create .a file in the bin dir

then uncomment:

#import "core/config/engine.h"

in the .m file, and notice that it will no longer build in xcode or terminal

so copy across the godot folder from cm_godot_plugin

(or get godot code from github and build from scratch following guide online for making plugins)

then add to header search paths in project settings:

$(SRCROOT)/godot

$(SRCROOT)/godot/platform/ios

now notice that building in both xcode and terminal give errors to do with standard libraries

e.g. could not find csdint

to fix this change the .m file to .mm

then it uses g++ compiler instead of gcc (and therefore uses CXXFLAGS from SConstruct)

both xcode and terminal build should now work

now copy across the _implementation .h and .mm files from cm_godot_plugin

and change any cm_godot_plugin or CmGodotPlugin to the right name

should still build fine

(might have to delete the .d and .o files generated in previous builds, and clean build folder)

now uncomment the previously commented out stuff in the original .m file

it should still compile

then copy across the .gdip file from the cm_godot_plugin

and change libcm_godot_plugin to lib[project name]

as well asCmGodotPlugin and cm_godot_plugin_init, etc

then build it with scons (maybe safe to delete old .o and .d files first)

and copy resulting .a file to godot project root folder -> ios -> plugins

also copy the .gdip file there

(actually maybe gdip doesn't technically need to be in the xcode proj at all!

but is a safe place to keep it for when needed anyway)

then open godot project and go to project->export

in options for ios there is a plugins section, plugin should be there. turn it on.

put some code in to godot code to test it, e.g.:

var cmGodotPlugin = null

func _ready():

	if Engine.has_singleton("CmGodotPlugin"):

		cmGodotPlugin = Engine.get_singleton("CmGodotPlugin")

...

if cmGodotPlugin:

	cmGodotPlugin.foo()

else:

	print("not running on ios")



-- notes --

original plugin example i used was from here:

https://github.com/naithar/godot_ios_plugin/tree/master

but i had to change some things

i had to change "core/engine.h" to "core/config/engine.h"

and a few other headers similarly were in different places in my godot folder

to what the example code expected

if need to send a signal from obj-c code to godot, check around 12 min mark here:

https://www.youtube.com/watch?v=Y6Iq71zZO10




