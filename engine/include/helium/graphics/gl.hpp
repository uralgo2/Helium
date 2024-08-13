#pragma once
#include <GL/glew.h>

namespace he::engine::graphics::gl
{
    enum class ShaderTypeEnum {
        Fragment = GL_FRAGMENT_SHADER,
        Vertex = GL_VERTEX_SHADER,
        Geometry = GL_GEOMETRY_SHADER,
        Compute = GL_COMPUTE_SHADER,
    };
    enum class BufferTypeEnum {
        Array = GL_ARRAY_BUFFER,
        ElementArray = GL_ELEMENT_ARRAY_BUFFER,
        Uniform = GL_UNIFORM_BUFFER,
        ShaderStorage = GL_SHADER_STORAGE_BUFFER,

    };

    template<ShaderTypeEnum TShaderType> struct Shader{
    private:
        unsigned int _object;
    public:
        
        Shader(const char* src){
            _object = glCreateShader((GLenum)TShaderType);
            glShaderSource(_object, 1, &src, nullptr);
        }

        void Compile(){
            glCompileShader(_object);

            GLint success;
            GLchar infoLog[512];
            glGetShaderiv(_object, GL_COMPILE_STATUS, &success);

            if(!success){
                std::string errorMessage = "Error occured while compiling shader: ";

                errorMessage += infoLog;

                throw std::runtime_error(errorMessage);
            }

        }
    };

    struct ShaderProgram;

    template<BufferTypeEnum TBuffer> struct Buffer;

} // namespace he::engine::graphics::gl
