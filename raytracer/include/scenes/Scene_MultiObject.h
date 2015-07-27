#pragma once
float ambient_kd = 0.15;

vp = new ViewPlane();
vp->SetWidth(640)
   .SetHeight(480)
   .SetPixelSize(1.f);
vp->SetFocalDistance(800.f);
vp->SetSamplerPtr(new Jitter(4));
imgBuffer = new ImageBufferPNG(vp->GetWidth(), vp->GetHeight());
tracerPtr = new MultiObjects(this);
Ambient* ambient_light = new Ambient();
this->ambient_ptr = ambient_light;
PointLight* light = new PointLight();
light->SetLocation(glm::vec3(100.f, 100.f, 100.f));
this->AddLight(light);
light = new PointLight();
light->SetLocation(glm::vec3(-100.f, -100.f, -100.f));
light->SetColor(RGBColor(glm::vec3(0.f, 0.f, 1.f)));
this->AddLight(light);
light = new PointLight();
light->SetLocation(glm::vec3(-100.f, -100.f, 100.f));
light->SetColor(RGBColor(glm::vec3(0.f, 1.f, 1.f)));
this->AddLight(light);
light = new PointLight();
light->SetLocation(glm::vec3(-100.f, 100.f, -100.f));
light->SetColor(RGBColor(glm::vec3(0.f, 1.f, 0.f)));
this->AddLight(light);

Matte* sphere_material = new Matte();
Lambertian* ambient_mat = new Lambertian();
Lambertian* diffuse_mat = new Lambertian();
ambient_mat->SetCd(RGBColor(glm::vec3(1.f, 0.f, 0.f)));
ambient_mat->SetKd(ambient_kd);
diffuse_mat->SetCd(RGBColor(glm::vec3(0.f, 1.f, 0.f)));
sphere_material->SetAmbient(ambient_mat);
sphere_material->SetDiffuse(diffuse_mat);
Sphere *msphere = new Sphere();
msphere->SetMaterial(sphere_material);
msphere->SetCenter(glm::vec3(-100.f, -100.f, -100.f));
msphere->SetRadius(85.0);
msphere->baseColor = RGBColor::red;
this->AddObject(msphere);

msphere = new Sphere();
sphere_material = new Matte();
ambient_mat = new Lambertian();
ambient_mat->SetCd(RGBColor(glm::vec3(1.f, 0.f, 0.f)));
ambient_mat->SetKd(ambient_kd);
diffuse_mat = new Lambertian();
diffuse_mat->SetCd(RGBColor(glm::vec3(0.f, 0.f, 1.f)));
sphere_material->SetAmbient(ambient_mat);
sphere_material->SetDiffuse(diffuse_mat);
msphere->SetMaterial(sphere_material);
msphere->SetCenter(glm::vec3(100.f, -100.f, -100.f));
msphere->SetRadius(65.f);
msphere->baseColor = RGBColor::yellow;
this->AddObject(msphere);

Plane* plane = new Plane(glm::vec3(0.f, 50.f, -10.f), glm::vec3(0.f, -1.0f, 0.f));
sphere_material = new Matte();
ambient_mat = new Lambertian();
ambient_mat->SetCd(RGBColor(glm::vec3(1.f, 0.f, 0.f)));
ambient_mat->SetKd(ambient_kd);
diffuse_mat = new Lambertian();
sphere_material->SetAmbient(ambient_mat);
sphere_material->SetDiffuse(diffuse_mat);
plane->SetMaterial(sphere_material);

this->AddObject(plane);

outputFileName = "MultiObject.png";
