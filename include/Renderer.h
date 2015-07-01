//
// Created by alex on 6/8/15.
//

#ifndef PROTOTYPE_ACTION_RENDERER_H
#define PROTOTYPE_ACTION_RENDERER_H

#include <iostream>
#include <memory>
#include <functional>
#include <GL/glew.h>
#include <GL/gl.h>
#include "GLWindow.h"

#include <Graphics/glew.h>
#include <SDL/SDL.h>

class Renderer final {
public:
    explicit Renderer();
    ~Renderer() = default;

    std::shared_ptr<sdl2::GLWindow> window() const;
    void init();
    void update();

    GLuint compile_shader(std::string shader, GLenum shader_type, int element_count) const;
    std::string load_shader(const std::string& shader_location) const;
    std::string shader_compilation_result(const GLuint shader) const;

private:
    std::shared_ptr<sdl2::GLWindow> window_;
    GLuint shader_program_;
    GLuint VAO_;
    GLuint VBO_;

};


#endif //PROTOTYPE_ACTION_RENDERER_H
