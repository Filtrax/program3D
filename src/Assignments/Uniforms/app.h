//
// Created by pbialas on 05.08.2020.
//

#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "glad/gl.h"
#include "Application/application.h"
#include "Application/utils.h"
#include "camera.h"
#include "camera_controller.h"


class SimpleShapeApplication : public xe::Application
{
public:
    SimpleShapeApplication(int width, int height, std::string title, bool debug) : Application(width, height, title, debug) {}

    void init() override;

    void frame() override;
    void framebuffer_resize_callback(int w, int h) override;
    Camera* camera_;
    void set_camera(Camera* camera) { camera_ = camera; }

    void scroll_callback(double xoffset, double yoffset) override {
        Application::scroll_callback(xoffset, yoffset);
        camera()->zoom(yoffset / -30.0f);
    }

    Camera* camera() { return camera_; }

    ~SimpleShapeApplication() {
        if (camera_) {
            delete camera_;
        }
    }

    void set_controller(CameraController* controller) { controller_ = controller; }

    void mouse_button_callback(int button, int action, int mods) {
        Application::mouse_button_callback(button, action, mods);
        if (controller_) {
            double x, y;
            glfwGetCursorPos(window_, &x, &y);
            if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
                controller_->LMB_pressed(x, y);
            if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
                controller_->LMB_released(x, y);
        }
    }

    void cursor_position_callback(double x, double y) {
        Application::cursor_position_callback(x, y);
        if (controller_) {
            controller_->mouse_moved(x, y);
        }
    }

private:
    GLuint vao_;
    std::vector<GLushort> indices;
    float fov_;
    float aspect_;
    float near_;
    float far_;
    glm::mat4 P_;
    glm::mat4 V_;
    GLuint pvm;
    CameraController* controller_;
};