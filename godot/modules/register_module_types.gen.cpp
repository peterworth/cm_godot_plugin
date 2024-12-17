// register_module_types.gen.cpp
/* THIS FILE IS GENERATED DO NOT EDIT */
#include "register_module_types.h"

#include "modules/modules_enabled.gen.h"

#include "modules/astcenc/register_types.h"
#include "modules/basis_universal/register_types.h"
#include "modules/bmp/register_types.h"
#include "modules/camera/register_types.h"
#include "modules/csg/register_types.h"
#include "modules/cvtt/register_types.h"
#include "modules/dds/register_types.h"
#include "modules/enet/register_types.h"
#include "modules/etcpak/register_types.h"
#include "modules/freetype/register_types.h"
#include "modules/gdscript/register_types.h"
#include "modules/glslang/register_types.h"
#include "modules/gltf/register_types.h"
#include "modules/gridmap/register_types.h"
#include "modules/hdr/register_types.h"
#include "modules/jpg/register_types.h"
#include "modules/jsonrpc/register_types.h"
#include "modules/ktx/register_types.h"
#include "modules/lightmapper_rd/register_types.h"
#include "modules/mbedtls/register_types.h"
#include "modules/meshoptimizer/register_types.h"
#include "modules/minimp3/register_types.h"
#include "modules/mobile_vr/register_types.h"
#include "modules/mono/register_types.h"
#include "modules/msdfgen/register_types.h"
#include "modules/multiplayer/register_types.h"
#include "modules/navigation/register_types.h"
#include "modules/noise/register_types.h"
#include "modules/ogg/register_types.h"
#include "modules/openxr/register_types.h"
#include "modules/raycast/register_types.h"
#include "modules/regex/register_types.h"
#include "modules/squish/register_types.h"
#include "modules/svg/register_types.h"
#include "modules/text_server_adv/register_types.h"
#include "modules/text_server_fb/register_types.h"
#include "modules/tga/register_types.h"
#include "modules/theora/register_types.h"
#include "modules/tinyexr/register_types.h"
#include "modules/upnp/register_types.h"
#include "modules/vhacd/register_types.h"
#include "modules/vorbis/register_types.h"
#include "modules/webp/register_types.h"
#include "modules/webrtc/register_types.h"
#include "modules/websocket/register_types.h"
#include "modules/webxr/register_types.h"
#include "modules/xatlas_unwrap/register_types.h"
#include "modules/zip/register_types.h"


void initialize_modules(ModuleInitializationLevel p_level) {
#ifdef MODULE_ASTCENC_ENABLED
	initialize_astcenc_module(p_level);
#endif
#ifdef MODULE_BASIS_UNIVERSAL_ENABLED
	initialize_basis_universal_module(p_level);
#endif
#ifdef MODULE_BMP_ENABLED
	initialize_bmp_module(p_level);
#endif
#ifdef MODULE_CAMERA_ENABLED
	initialize_camera_module(p_level);
#endif
#ifdef MODULE_CSG_ENABLED
	initialize_csg_module(p_level);
#endif
#ifdef MODULE_CVTT_ENABLED
	initialize_cvtt_module(p_level);
#endif
#ifdef MODULE_DDS_ENABLED
	initialize_dds_module(p_level);
#endif
#ifdef MODULE_ENET_ENABLED
	initialize_enet_module(p_level);
#endif
#ifdef MODULE_ETCPAK_ENABLED
	initialize_etcpak_module(p_level);
#endif
#ifdef MODULE_FREETYPE_ENABLED
	initialize_freetype_module(p_level);
#endif
#ifdef MODULE_GDSCRIPT_ENABLED
	initialize_gdscript_module(p_level);
#endif
#ifdef MODULE_GLSLANG_ENABLED
	initialize_glslang_module(p_level);
#endif
#ifdef MODULE_GLTF_ENABLED
	initialize_gltf_module(p_level);
#endif
#ifdef MODULE_GRIDMAP_ENABLED
	initialize_gridmap_module(p_level);
#endif
#ifdef MODULE_HDR_ENABLED
	initialize_hdr_module(p_level);
#endif
#ifdef MODULE_JPG_ENABLED
	initialize_jpg_module(p_level);
#endif
#ifdef MODULE_JSONRPC_ENABLED
	initialize_jsonrpc_module(p_level);
#endif
#ifdef MODULE_KTX_ENABLED
	initialize_ktx_module(p_level);
#endif
#ifdef MODULE_LIGHTMAPPER_RD_ENABLED
	initialize_lightmapper_rd_module(p_level);
#endif
#ifdef MODULE_MBEDTLS_ENABLED
	initialize_mbedtls_module(p_level);
#endif
#ifdef MODULE_MESHOPTIMIZER_ENABLED
	initialize_meshoptimizer_module(p_level);
#endif
#ifdef MODULE_MINIMP3_ENABLED
	initialize_minimp3_module(p_level);
#endif
#ifdef MODULE_MOBILE_VR_ENABLED
	initialize_mobile_vr_module(p_level);
#endif
#ifdef MODULE_MONO_ENABLED
	initialize_mono_module(p_level);
#endif
#ifdef MODULE_MSDFGEN_ENABLED
	initialize_msdfgen_module(p_level);
#endif
#ifdef MODULE_MULTIPLAYER_ENABLED
	initialize_multiplayer_module(p_level);
#endif
#ifdef MODULE_NAVIGATION_ENABLED
	initialize_navigation_module(p_level);
#endif
#ifdef MODULE_NOISE_ENABLED
	initialize_noise_module(p_level);
#endif
#ifdef MODULE_OGG_ENABLED
	initialize_ogg_module(p_level);
#endif
#ifdef MODULE_OPENXR_ENABLED
	initialize_openxr_module(p_level);
#endif
#ifdef MODULE_RAYCAST_ENABLED
	initialize_raycast_module(p_level);
#endif
#ifdef MODULE_REGEX_ENABLED
	initialize_regex_module(p_level);
#endif
#ifdef MODULE_SQUISH_ENABLED
	initialize_squish_module(p_level);
#endif
#ifdef MODULE_SVG_ENABLED
	initialize_svg_module(p_level);
#endif
#ifdef MODULE_TEXT_SERVER_ADV_ENABLED
	initialize_text_server_adv_module(p_level);
#endif
#ifdef MODULE_TEXT_SERVER_FB_ENABLED
	initialize_text_server_fb_module(p_level);
#endif
#ifdef MODULE_TGA_ENABLED
	initialize_tga_module(p_level);
#endif
#ifdef MODULE_THEORA_ENABLED
	initialize_theora_module(p_level);
#endif
#ifdef MODULE_TINYEXR_ENABLED
	initialize_tinyexr_module(p_level);
#endif
#ifdef MODULE_UPNP_ENABLED
	initialize_upnp_module(p_level);
#endif
#ifdef MODULE_VHACD_ENABLED
	initialize_vhacd_module(p_level);
#endif
#ifdef MODULE_VORBIS_ENABLED
	initialize_vorbis_module(p_level);
#endif
#ifdef MODULE_WEBP_ENABLED
	initialize_webp_module(p_level);
#endif
#ifdef MODULE_WEBRTC_ENABLED
	initialize_webrtc_module(p_level);
#endif
#ifdef MODULE_WEBSOCKET_ENABLED
	initialize_websocket_module(p_level);
#endif
#ifdef MODULE_WEBXR_ENABLED
	initialize_webxr_module(p_level);
#endif
#ifdef MODULE_XATLAS_UNWRAP_ENABLED
	initialize_xatlas_unwrap_module(p_level);
#endif
#ifdef MODULE_ZIP_ENABLED
	initialize_zip_module(p_level);
#endif

}

void uninitialize_modules(ModuleInitializationLevel p_level) {
#ifdef MODULE_ASTCENC_ENABLED
	uninitialize_astcenc_module(p_level);
#endif
#ifdef MODULE_BASIS_UNIVERSAL_ENABLED
	uninitialize_basis_universal_module(p_level);
#endif
#ifdef MODULE_BMP_ENABLED
	uninitialize_bmp_module(p_level);
#endif
#ifdef MODULE_CAMERA_ENABLED
	uninitialize_camera_module(p_level);
#endif
#ifdef MODULE_CSG_ENABLED
	uninitialize_csg_module(p_level);
#endif
#ifdef MODULE_CVTT_ENABLED
	uninitialize_cvtt_module(p_level);
#endif
#ifdef MODULE_DDS_ENABLED
	uninitialize_dds_module(p_level);
#endif
#ifdef MODULE_ENET_ENABLED
	uninitialize_enet_module(p_level);
#endif
#ifdef MODULE_ETCPAK_ENABLED
	uninitialize_etcpak_module(p_level);
#endif
#ifdef MODULE_FREETYPE_ENABLED
	uninitialize_freetype_module(p_level);
#endif
#ifdef MODULE_GDSCRIPT_ENABLED
	uninitialize_gdscript_module(p_level);
#endif
#ifdef MODULE_GLSLANG_ENABLED
	uninitialize_glslang_module(p_level);
#endif
#ifdef MODULE_GLTF_ENABLED
	uninitialize_gltf_module(p_level);
#endif
#ifdef MODULE_GRIDMAP_ENABLED
	uninitialize_gridmap_module(p_level);
#endif
#ifdef MODULE_HDR_ENABLED
	uninitialize_hdr_module(p_level);
#endif
#ifdef MODULE_JPG_ENABLED
	uninitialize_jpg_module(p_level);
#endif
#ifdef MODULE_JSONRPC_ENABLED
	uninitialize_jsonrpc_module(p_level);
#endif
#ifdef MODULE_KTX_ENABLED
	uninitialize_ktx_module(p_level);
#endif
#ifdef MODULE_LIGHTMAPPER_RD_ENABLED
	uninitialize_lightmapper_rd_module(p_level);
#endif
#ifdef MODULE_MBEDTLS_ENABLED
	uninitialize_mbedtls_module(p_level);
#endif
#ifdef MODULE_MESHOPTIMIZER_ENABLED
	uninitialize_meshoptimizer_module(p_level);
#endif
#ifdef MODULE_MINIMP3_ENABLED
	uninitialize_minimp3_module(p_level);
#endif
#ifdef MODULE_MOBILE_VR_ENABLED
	uninitialize_mobile_vr_module(p_level);
#endif
#ifdef MODULE_MONO_ENABLED
	uninitialize_mono_module(p_level);
#endif
#ifdef MODULE_MSDFGEN_ENABLED
	uninitialize_msdfgen_module(p_level);
#endif
#ifdef MODULE_MULTIPLAYER_ENABLED
	uninitialize_multiplayer_module(p_level);
#endif
#ifdef MODULE_NAVIGATION_ENABLED
	uninitialize_navigation_module(p_level);
#endif
#ifdef MODULE_NOISE_ENABLED
	uninitialize_noise_module(p_level);
#endif
#ifdef MODULE_OGG_ENABLED
	uninitialize_ogg_module(p_level);
#endif
#ifdef MODULE_OPENXR_ENABLED
	uninitialize_openxr_module(p_level);
#endif
#ifdef MODULE_RAYCAST_ENABLED
	uninitialize_raycast_module(p_level);
#endif
#ifdef MODULE_REGEX_ENABLED
	uninitialize_regex_module(p_level);
#endif
#ifdef MODULE_SQUISH_ENABLED
	uninitialize_squish_module(p_level);
#endif
#ifdef MODULE_SVG_ENABLED
	uninitialize_svg_module(p_level);
#endif
#ifdef MODULE_TEXT_SERVER_ADV_ENABLED
	uninitialize_text_server_adv_module(p_level);
#endif
#ifdef MODULE_TEXT_SERVER_FB_ENABLED
	uninitialize_text_server_fb_module(p_level);
#endif
#ifdef MODULE_TGA_ENABLED
	uninitialize_tga_module(p_level);
#endif
#ifdef MODULE_THEORA_ENABLED
	uninitialize_theora_module(p_level);
#endif
#ifdef MODULE_TINYEXR_ENABLED
	uninitialize_tinyexr_module(p_level);
#endif
#ifdef MODULE_UPNP_ENABLED
	uninitialize_upnp_module(p_level);
#endif
#ifdef MODULE_VHACD_ENABLED
	uninitialize_vhacd_module(p_level);
#endif
#ifdef MODULE_VORBIS_ENABLED
	uninitialize_vorbis_module(p_level);
#endif
#ifdef MODULE_WEBP_ENABLED
	uninitialize_webp_module(p_level);
#endif
#ifdef MODULE_WEBRTC_ENABLED
	uninitialize_webrtc_module(p_level);
#endif
#ifdef MODULE_WEBSOCKET_ENABLED
	uninitialize_websocket_module(p_level);
#endif
#ifdef MODULE_WEBXR_ENABLED
	uninitialize_webxr_module(p_level);
#endif
#ifdef MODULE_XATLAS_UNWRAP_ENABLED
	uninitialize_xatlas_unwrap_module(p_level);
#endif
#ifdef MODULE_ZIP_ENABLED
	uninitialize_zip_module(p_level);
#endif

}
