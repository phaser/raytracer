#pragma once
vp = new ViewPlane();
vp->SetWidth(640)
   .SetHeight(480)
   .SetPixelSize(1.f);
vp->SetFocalDistance(800.f);
vp->SetSamplerPtr(new Jitter(4));
imgBuffer = new ImageBufferPNG(vp->GetWidth(), vp->GetHeight());
tracerPtr = new MultiObjects(this);

sphere.SetCenter(glm::vec3(0.f, 0.f, 0.f));
sphere.SetRadius(85.0);
Sphere *msphere = new Sphere();
msphere->SetCenter(glm::vec3(-100.f, -100.f, -100.f));
msphere->SetRadius(85.0);
msphere->baseColor = RGBColor::red;
this->AddObject(msphere);
msphere = new Sphere();
msphere->SetCenter(glm::vec3(100.f, -100.f, -100.f));
msphere->SetRadius(65.f);
msphere->baseColor = RGBColor::yellow;
this->AddObject(msphere);
Plane* plane = new Plane(glm::vec3(0.f, 50.f, -10.f), glm::vec3(0.f, -1.0f, 0.f));
this->AddObject(plane);

Light light;
light.SetPosition(glm::vec3(100.f, -100.f, 100.f));
light.SetDirection(glm::vec3(10.f, -10.f, 10.f));
this->AddLight(light);

outputFileName = "MultiObject.png";
