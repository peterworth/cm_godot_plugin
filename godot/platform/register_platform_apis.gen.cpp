#include "register_platform_apis.h"
#include "android/api/api.h"
#include "ios/api/api.h"
#include "web/api/api.h"

void register_platform_apis() {
	register_android_api();
	register_ios_api();
	register_web_api();
}

void unregister_platform_apis() {
	unregister_android_api();
	unregister_ios_api();
	unregister_web_api();
}
