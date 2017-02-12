#include <cmath>
#include <iostream>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vector.h"

class Camera {
public:
	Vec3 loc;
	float camPitch, camYaw;
	float moveVel;
	float mouseVel;
	bool mI, isMoved;
	void LockCamera();
	Camera();
	void MoveCamera(float dist, float dir);
	void MoveCameraUp(float dist, float dir);
	void Control(float movevel, float mousevel, bool mi);
	void UpdateCamera();

	void MouseIn(bool b);
};
