#pragma once

#include <BasicCamera/Camera.h>
#include <BasicCamera/Fwd.h>
#include <BasicCamera/basiccamera_export.h>

class BASICCAMERA_EXPORT basicCamera::PerspectiveCamera
    : public CameraProjection {
 public:
  PerspectiveCamera(float fovy   = glm::radians(90.f),
                    float aspect = 1024.f / 768.f,
                    float near   = 0.1f,
                    float far    = 1000.f);
  virtual ~PerspectiveCamera();
  virtual glm::mat4 getProjection();
  float             getNear() const;
  float             getFar() const;
  float             getFovy() const;
  float             getAspect() const;
  void              setNear(float value);
  void              setFar(float value);
  void              setFovy(float value);
  void              setAspect(float value);

 protected:
  float     _near = 1.f;
  float     _far = 100.f; 
  float     _fovy = glm::half_pi<float>();
  float     _aspect = 1.f;
  glm::mat4 _projection = glm::mat4(1.f);
  bool      _recompute = true;
  void      _compute();
};
