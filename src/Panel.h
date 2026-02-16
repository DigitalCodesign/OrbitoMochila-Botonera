#ifndef Panel_h
#define Panel_h

class Botonera;
class Panel
{
    public: 

        friend class OrbitoBotonera;
        static const uint8_t Pulsador1 = 6;
        static const uint8_t Pulsador2 = 7;
        static const uint8_t Pulsador3 = 8;
        static const uint8_t Pulsador4 = 9;
        static const uint8_t Pulsador5 = 10;
        static const uint8_t Pulsador6 = 11;
        static const uint8_t Pulsador7 = 12;

    private:

        static const uint8_t _Pulsador1 = PORT_BACK_IO_2_5;
        static const uint8_t _Pulsador2 = PORT_BACK_IO_2_3;
        static const uint8_t _Pulsador3 = PORT_BACK_IO_2_3;
        static const uint8_t _Pulsador4 = PORT_BACK_IO_2_2;
        static const uint8_t _Pulsador5 = PORT_BACK_IO_2_2;
        static const uint8_t _Pulsador6 = PORT_BACK_IO_2_1;
        static const uint8_t _Pulsador7 = PORT_BACK_IO_2_1;

};

#endif