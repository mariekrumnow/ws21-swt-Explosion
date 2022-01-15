// Author: Tobias

#ifndef BOMBERMAN_GRAPHICS_COLOR_H_
#define BOMBERMAN_GRAPHICS_COLOR_H_

#include <cstdint>

namespace graphics {

/// A representation of an RGBA color

class Color {
public:

    /// Assigns the attributes of Color
    ///
    /// \param red The color value for the red portion
    /// \param green The color value for the green portion
    /// \param blue The color value for the blue portion
    /// \param alpha The value for the transparency
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    : red_(red), green_(green), blue_(blue), alpha_(alpha) {}

    uint8_t red_; ///< The color value for the red portion
    uint8_t green_; ///< The color value for the green portion
    uint8_t blue_; ///< The color value for the blue portion
    uint8_t alpha_; ///< The value for the transparency
};

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_COLOR_H_
