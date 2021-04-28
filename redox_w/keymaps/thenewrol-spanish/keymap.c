#include QMK_KEYBOARD_H
#define LEADER_TIMEOUT 500
#include "keymap_spanish.h"

//Definiendo variables de capas
#define _QWERTY 0
#define _SYMB 1
#define _GAMING 2
#define _NAV 3
#define _ADJUST 4

//Layouts
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  GAMING,
  NAV,
  ADJUST
};

//Define los tipos de tap dance a usar, tap => precionado y hold -> mantiene precionado
typedef enum {
   TD_NONE,
   TD_UNKNOWN,
   TD_SINGLE_TAP,
   TD_SINGLE_HOLD
   //TD_DOUBLE_TAP,
   //TD_DOUBLE_HOLD,
   //TD_DOUBLE_SINGLE_TAP, // Send two single taps
   //TD_TRIPLE_TAP,
   //TD_TRIPLE_HOLD
} td_state_t;

//State tap
typedef struct {
   bool is_press_action;
   td_state_t state;
} td_tap_t;

//Definiendo teclas tap dance
enum TD_Kodes{
   AIC, // (ACI) Acento Isquierda, Comilla, Interrogante
   AAI // (AAI) Acento Derecha, Abrir Admiracion, Abrir interrogante
};

//Definiendo las teclas peronalizadas
enum custom_keys{
   B_MAYUS
};

//Definiendo mapa de teclado
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,ES_LBRC ,                          ES_RBRC ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,TD(AIC) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     B_MAYUS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,ES_LCBR ,                          ES_RCBR ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,ES_NTIL ,TD(AAI) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_LEFT ,KC_RGHT ,        KC_DEL  ,KC_ENT  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,ES_LABK ,MO(_SYMB),KC_LEAD,     KC_LALT ,    KC_UP   ,KC_DOWN ,        KC_LGUI ,KC_SPC  ,    KC_RALT ,     ES_LABK ,TG(_GAMING),NAV  ,KC_RCTL
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,                          _______ ,KC_PSLS ,_______	,KC_P7 	 ,KC_P8   ,KC_P9  ,KC_PMNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,_______ ,                          _______ ,KC_PAST ,_______	,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,KC_GRV  ,_______	,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     TG(_QWERTY), _______ ,_______ ,_______ , KC_LALT ,    _______ ,_______ ,        _______ ,_______ ,    KC_RALT ,     _______ ,KC_P0   ,KC_PDOT ,KC_PENT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,  KC_Q  ,  KC_W  ,_______ ,_______ ,_______ ,_______  ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_BSPC ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     TG(_QWERTY), _______ ,_______ ,_______ , KC_ENTER,    KC_SPACE,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     QWERTY  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,_______ ,        _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     QWERTY  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};//layer_on (MY_LAYER);  //  layer_off (MY_LAYER);

//Funcion asociada a los eventos de tap dance
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return TD_SINGLE_TAP;
         }else{
            return TD_SINGLE_HOLD;
         }
    }else return TD_UNKNOWN;
}

//Inicializa una instancia 'td_tap_t' para el tap dance 'x'
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

//Funcion asociadas con el registro de acciones de tap dance
void x_finished(qk_tap_dance_state_t *state, void *user_data) {
   xtap_state.state = cur_dance(state);
   switch (xtap_state.state) {
      case TD_SINGLE_TAP: register_code(KC_ESC); break;
      case TD_SINGLE_HOLD: register_code(KC_GRV); break;
      default: xtap_state.state = TD_UNKNOWN;
   }
}
//Funcion de reseteo de la tecla tap dance
void x_reset(qk_tap_dance_state_t *state, void *user_data) {
   switch (xtap_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
      case TD_SINGLE_HOLD: unregister_code(KC_GRV); break;
      default: xtap_state.state = TD_NONE;
   }
   xtap_state.state = TD_NONE;
}

//Asociar nustro tap dance a una funcionalidad
qk_tap_dance_action_t tap_dance_actions[] = {
   [AIC] = ACTION_TAP_DANCE_DOUBLE(ES_GRV, KC_MINS),
   [AAI] = ACTION_TAP_DANCE_DOUBLE(ES_ACUT, KC_EQL)
   //[X_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

LEADER_EXTERNS () ;
bool did_leader_succed;
void matrix_scan_user ( void ) {
   LEADER_DICTIONARY () { 
      did_leader_succed = leading = false ;
      // Reemplaza las secuencias siguientes con tus propias secuencias.
      SEQ_ONE_KEY ( ES_LABK ) {
         // Cuando presiono KC_LEAD y luego T, esto envía CTRL + SHIFT + T
         register_code(KC_LSFT);
         register_code(ES_LABK);
         clear_keyboard();
      }
      leader_end();
   }
}

bool bloc_mayus = false; //Estado del blocq mayus activado o desactivado
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch(keycode) {
      case B_MAYUS://Permite controlar el estado del vloq mayus
         if (record->event.pressed) {
            if(bloc_mayus){// Apaga el led si el bloq mayus esta activado
               set_led_off;
               bloc_mayus = false;
            }else{// Enciende el led si el bloq mayus no esta activado
               set_led_red;
               bloc_mayus = true;
            }
            register_code(KC_CAPS); //Eviamos la pulsacion del bloq mayus
         }else{
            unregister_code(KC_CAPS); //Liberamos la pulsacion del bloq mayus
         }
         return false;
         break;
   }
   return true;
}

// Encender luz al selecionar una capa
layer_state_t layer_state_set_user(layer_state_t state) {
   switch (get_highest_layer(state)) {
      case _QWERTY:
         set_led_off;
         break;
      case _SYMB:
         set_led_green; //Enciende el azul
         break;
      case _GAMING:
         set_led_blue; //Enciende el azul
         break;
      case _NAV:
         set_led_blue; //Enciende el rojo
         break;
      case _ADJUST:
         set_led_red; //Enciende amarillo
         break;
      default:
         break;
   }
   return state;
}
//qmk compile -kb redox_w -km thenewrol-spain
