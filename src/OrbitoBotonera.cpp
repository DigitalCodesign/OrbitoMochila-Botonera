#include "OrbitoBotonera.h"

OrbitoBotonera::OrbitoBotonera(){

}

bool OrbitoBotonera::_high_switch(uint16_t analog_value){
    bool return_value = 0;
    if((analog_value < (_switch_value_high + _switch_value_range))&&(analog_value > (_switch_value_high - _switch_value_range))){
        return_value = 1;
    }
    else{
        return_value = 0;
    }
    return return_value;
}

bool OrbitoBotonera::_low_switch(uint16_t analog_value){
    bool return_value = 0;
    if((analog_value < (_switch_value_low + _switch_value_range))&&(analog_value > (_switch_value_low - _switch_value_range))){
        return_value = 1;
    }
    else{
        return_value = 0;
    }
    return return_value;
}

bool OrbitoBotonera::leerPulsador(uint8_t pulsador){
    bool value;
    uint16_t analog_value;
    switch(pulsador){
        case Cruceta::arriba:
            analog_value = _Orbito.System.analogRead(Cruceta::_arriba);
            value = _high_switch(analog_value);
            break;
        case Cruceta::abajo:
            analog_value = _Orbito.System.analogRead(Cruceta::_abajo);
            value = _low_switch(analog_value);
            break;
        case Cruceta::izquierda:
            analog_value = _Orbito.System.analogRead(Cruceta::_izquierda);
            value = _low_switch(analog_value);
            break;
        case Cruceta::derecha:
            analog_value = _Orbito.System.analogRead(Cruceta::_derecha);
            value = _high_switch(analog_value);
            break;
        case Cruceta::centro:
            analog_value = _Orbito.System.analogRead(Cruceta::_centro);
            value = _low_switch(analog_value);
            break;
        case Panel::Pulsador1:
            analog_value = _Orbito.System.analogRead(Panel::_Pulsador1);
            value = _high_switch(analog_value);
            break;
        case Panel::Pulsador2:
            analog_value = _Orbito.System.analogRead(Panel::_Pulsador2);
            value = _low_switch(analog_value);
            break; 
        case Panel::Pulsador3:
            analog_value = _Orbito.System.analogRead(Panel::_Pulsador3);
            value = _high_switch(analog_value);
            break;
        case Panel::Pulsador4:
            analog_value = _Orbito.System.analogRead(Panel::_Pulsador4);
            value = _high_switch(analog_value);
            break;   
        case Panel::Pulsador5:
            analog_value = _Orbito.System.analogRead(Panel::_Pulsador5);
            value = _low_switch(analog_value);
            break; 
        case Panel::Pulsador6:
            analog_value = _Orbito.System.analogRead(Panel::_Pulsador6);
            value = _low_switch(analog_value);
            break; 
        case Panel::Pulsador7:
            analog_value = _Orbito.System.analogRead(Panel::_Pulsador7);
            value = _high_switch(analog_value);
            break;          
    }
    return value;
}
