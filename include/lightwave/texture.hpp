/**
 * @file texture.hpp
 * @brief Contains the Texture interface, which models spatially varying
 * properties of materials.
 */

#pragma once

#include <lightwave/color.hpp>
#include <lightwave/core.hpp>
#include <lightwave/math.hpp>

namespace lightwave {

/// @brief Models spatially varying material properties (e.g., images or
/// procedural noise).
class Texture : public Object {
public:
    /**
     * @brief Returns the color at a given texture coordinate.
     * For most applications, the input point will lie in the unit square
     * [0,1)^2, but points outside this domain are also allowed.
     */
    virtual Color evaluate(const Point2 &uv, const Context &cont) const = 0;
    /**
     * @brief Returns the color at a given texture coordinate for a given mip
     * level. For most applications, the input point will lie in the unit square
     * [0,1)^2, but points outside this domain are also allowed.
     */
    virtual Color evaluate(const Point2 &uv, const Context &cont,
                           int map) const {
        return evaluate(uv, cont);
    }
    /**
     * @brief Returns a scalar value at a given texture coordinate.
     * For most applications, the input point will lie in the unit square
     * [0,1)^2, but points outside this domain are also allowed.
     */
    virtual float scalar(const Point2 &uv, const Context &cont) const {
        // arbitrary mapping from RGB images to scalar values (typically those
        // will be grayscale anyway and we would ideally have a separate texture
        // interface for scalar values)
        return evaluate(uv, cont).r();
    }
    /**
     * @brief Returns a scalar value at a given texture coordinate for a given
     * mip level. For most applications, the input point will lie in the unit
     * square [0,1)^2, but points outside this domain are also allowed.
     */
    virtual float scalar(const Point2 &uv, const Context &cont, int mip) const {
        // arbitrary mapping from RGB images to scalar values (typically those
        // will be grayscale anyway and we would ideally have a separate texture
        // interface for scalar values)
        return evaluate(uv, cont, mip).r();
    }
};

} // namespace lightwave