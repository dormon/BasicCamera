#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <BasicCamera/Camera.h>
#include <BasicCamera/Fwd.h>
#include <BasicCamera/basiccamera_export.h>

class BASICCAMERA_EXPORT basicCamera::FreeLookCamera : public CameraTransform {
 public:
  FreeLookCamera();
  virtual ~FreeLookCamera();
  virtual glm::mat4 getView();
  glm::mat4         getRotation();
  void              up(float dy);
  void              down(float dy);
  void              left(float dx);
  void              right(float dx);
  void              forward(float dz);
  void              back(float dz);
  void              move(size_t axis, float d);
  void              setPosition(glm::vec3 const& p);
  void              addPosition(glm::vec3 const& delta);
  glm::vec3         getPosition() const;
  float             getXAngle() const;
  float             getYAngle() const;
  float             getZAngle() const;
  float             getAngle(size_t axis) const;
  void              setXAngle(float value);
  void              setYAngle(float value);
  void              setZAngle(float value);
  void              setAngle(size_t axis, float value);
  void              addXAngle(float delta);
  void              addYAngle(float delta);
  void              addZAngle(float delta);
  void              addAngle(size_t axis, float delta);
  void setRotation(glm::vec3 const& viewVector, glm::vec3 const& upVector);

 protected:
  glm::vec3 _angles            = glm::vec3(0.f);
  bool      _recomputeView     = true;
  bool      _recomputeRotation = true;
  glm::vec3 _position          = glm::vec3(0.f);
  glm::mat4 _view              = glm::mat4(1.f);
  glm::mat4 _rotation          = glm::mat4(1.f);
  void      _computeView();
  void      _computeRotation();
};
