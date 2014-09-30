#include <pebble.h>
#include "main_window.h"
#include "data_framework.h"
	
// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_ing_big_white;
static GFont s_res_roboto_condensed_21;
static GBitmap *s_res_image_eurosign_white;
static BitmapLayer *s_bitmaplayer_2;
TextLayer *s_textlayer_1;
static BitmapLayer *s_bitmaplayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, 0);
  
  s_res_image_ing_big_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ING_BIG_WHITE);
  s_res_roboto_condensed_21 = fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21);
  s_res_image_eurosign_white = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_EUROSIGN_WHITE);
  // s_bitmaplayer_2
  s_bitmaplayer_2 = bitmap_layer_create(GRect(-124, -16, 300, 300));
  bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_image_ing_big_white);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_2);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(0, 56, 144, 27));
  text_layer_set_background_color(s_textlayer_1, GColorBlack);
  text_layer_set_text_color(s_textlayer_1, GColorWhite);
  text_layer_set_text(s_textlayer_1, "Laden...");
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_1, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(-9, 55, 40, 40));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_image_eurosign_white);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
}
void set_balance_text_layer(const char* text) 
{ 
	text_layer_set_text(s_textlayer_1, text); 
}
static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_2);
  text_layer_destroy(s_textlayer_1);
  bitmap_layer_destroy(s_bitmaplayer_1);
  gbitmap_destroy(s_res_image_ing_big_white);
  gbitmap_destroy(s_res_image_eurosign_white);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_main_window(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_main_window(void) {
  window_stack_remove(s_window, true);
}
