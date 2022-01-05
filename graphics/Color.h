// Author: Tobias

#ifndef BOMBERMAN_GRAPHICS_COLOR_H_
#define BOMBERMAN_GRAPHICS_COLOR_H_

#include <cstdint>

namespace graphics {

/// Color: a representation of an RGBA color
    class Color {
    public:
        uint8_t red_;
        uint8_t green_;
        uint8_t blue_;
        uint8_t alpha_;
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
                : red_(red), green_(green), blue_(blue), alpha_(alpha) {}
    };

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_COLOR_H_
