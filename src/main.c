#include <pebble.h>
#include "main_window.h"
#include "data_framework.h"

enum {
		KEY_BALANCE = 0
};  
void out_sent_handler(DictionaryIterator *sent, void *context) {
   APP_LOG(APP_LOG_LEVEL_DEBUG, "Appmessage Delivered");
 }

	char *translate_error(AppMessageResult result) {
  switch (result) {
    case APP_MSG_OK: return "APP_MSG_OK";
    case APP_MSG_SEND_TIMEOUT: return "APP_MSG_SEND_TIMEOUT";
    case APP_MSG_SEND_REJECTED: return "APP_MSG_SEND_REJECTED";
    case APP_MSG_NOT_CONNECTED: return "APP_MSG_NOT_CONNECTED";
    case APP_MSG_APP_NOT_RUNNING: return "APP_MSG_APP_NOT_RUNNING";
    case APP_MSG_INVALID_ARGS: return "APP_MSG_INVALID_ARGS";
    case APP_MSG_BUSY: return "APP_MSG_BUSY";
    case APP_MSG_BUFFER_OVERFLOW: return "APP_MSG_BUFFER_OVERFLOW";
    case APP_MSG_ALREADY_RELEASED: return "APP_MSG_ALREADY_RELEASED";
    case APP_MSG_CALLBACK_ALREADY_REGISTERED: return "APP_MSG_CALLBACK_ALREADY_REGISTERED";
    case APP_MSG_CALLBACK_NOT_REGISTERED: return "APP_MSG_CALLBACK_NOT_REGISTERED";
    case APP_MSG_OUT_OF_MEMORY: return "APP_MSG_OUT_OF_MEMORY";
    case APP_MSG_CLOSED: return "APP_MSG_CLOSED";
    case APP_MSG_INTERNAL_ERROR: return "APP_MSG_INTERNAL_ERROR";
    default: return "UNKNOWN ERROR";
  }
}
 void out_failed_handler(DictionaryIterator *failed, AppMessageResult reason, void *context) {
 }

 void in_received_handler(DictionaryIterator *iter, void *context) {
    Tuple *t = dict_read_first(iter);
    while(t != NULL)
    {
        int key = t->key;
				APP_LOG(APP_LOG_LEVEL_DEBUG, "Key %d recieved!", (int)t->key);
  			char string_value[20];
  			strncpy(string_value, t->value->cstring, 20);
				set_balance_buffer(string_value);
			  APP_LOG(APP_LOG_LEVEL_DEBUG, "Balance: %s", get_balance_buffer());
				set_balance_text_layer(get_balance_buffer());
        t = dict_read_next(iter);
    }
 }


 void in_dropped_handler(AppMessageResult reason, void *context) {
   // incoming message dropped
 }
void pokePhone(void)
{
	// Begin dictionary
  DictionaryIterator *iter;
  app_message_outbox_begin(&iter);

  // Add a key-value pair
  dict_write_uint8(iter, 0, 0);

  // Send the message!
  app_message_outbox_send();
}
int main(void) {
  app_message_register_inbox_received(in_received_handler);
   app_message_register_inbox_dropped(in_dropped_handler);
   app_message_register_outbox_sent(out_sent_handler);
   app_message_register_outbox_failed(out_failed_handler);


   const uint32_t inbound_size = 64;
   const uint32_t outbound_size = 64;
   app_message_open(inbound_size, outbound_size);
  show_main_window();
	//window_set_click_config_provider(&window, (ClickConfigProvider) config_provider);
	//pokePhone();
  app_event_loop();
  return 0;
}

