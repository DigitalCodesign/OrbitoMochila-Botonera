#ifndef Cruceta_h
#define Cruceta_h

class Botonera;
class Cruceta
{
    public: 

        friend class OrbitoBotonera;
        static const uint8_t arriba = 1;
        static const uint8_t abajo = 2;
        static const uint8_t izquierda = 3;
        static const uint8_t derecha = 4;
        static const uint8_t centro = 5;

    private: 

        static const uint8_t _arriba = PORT_BACK_IO_2_4;
        static const uint8_t _abajo = PORT_BACK_IO_2_6;
        static const uint8_t _izquierda = PORT_BACK_IO_2_4;
        static const uint8_t _derecha = PORT_BACK_IO_2_6;
        static const uint8_t _centro = PORT_BACK_IO_2_5;
};
#endif