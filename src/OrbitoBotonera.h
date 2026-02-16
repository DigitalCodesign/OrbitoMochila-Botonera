#ifndef OrbitoBotonera_h
#define OrbitoBotonera_h

#include <Orbito.h>
#include "Cruceta.h"
#include "Panel.h"

class OrbitoBotonera
{

    public:
        
        OrbitoBotonera();
        bool leerPulsador(uint8_t pulsador);
        Cruceta cruceta;
        Panel panel;


    private:
        bool _high_switch(uint16_t analog_value);
        bool _low_switch(uint16_t analog_value);
        uint16_t _switch_value_high = 2784;
        uint16_t _switch_value_low = 1015;
        uint16_t _switch_value_range = 600;
        OrbitoRobot _Orbito;


};

#endif