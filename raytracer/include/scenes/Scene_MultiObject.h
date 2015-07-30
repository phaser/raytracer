#pragma once
float ambient_kd = 0.15;

vp = new ViewPlane();
vp->SetWidth(640)
   .SetHeight(480)
   .SetPixelSize(1.f);
vp->SetFocalDistance(800.f);
LOG(INFO) << "Jitter Sampler with 64 samples per pixel.";
vp->SetSamplerPtr(new Jitter(64));
imgBuffer = new ImageBufferPNG(vp->GetWidth(), vp->GetHeight());
tracerPtr = new MultiObjects(this);
Ambient* ambient_light = new Ambient();
this->ambient_ptr = ambient_light;
PointLight* light = new PointLight();
light->SetLocation(glm::vec3(0.f, -10.f, 100.f));
this->AddLight(light);
light = new PointLight();
light->SetLocation(glm::vec3(-200.f, -200.f, 200.f));
light->SetColor(RGBColor(glm::vec3(0.f, 0.f, 1.f)));
this->AddLight(light);
light = new PointLight();
light->SetLocation(glm::vec3(-200.f, -200.f, 200.f));
light->SetColor(RGBColor(glm::vec3(0.f, 1.f, 1.f)));
this->AddLight(light);
light = new PointLight();
light->SetLocation(glm::vec3(-200.f, -200.f, 200.f));
light->SetColor(RGBColor(glm::vec3(0.f, 1.f, 0.f)));
this->AddLight(light);


Phong* sphere_material = new Phong();
Lambertian* ambient_mat = new Lambertian();
Lambertian* diffuse_mat = new Lambertian();
GlossySpecular* specular_mat = new GlossySpecular();
ambient_mat->SetCd(RGBColor(glm::vec3(1.f, 0.f, 0.f)));
ambient_mat->SetKd(ambient_kd);
diffuse_mat->SetCd(RGBColor(glm::vec3(0.f, 1.f, 0.f)));
sphere_material->SetAmbient(ambient_mat);
sphere_material->SetDiffuse(diffuse_mat);
sphere_material->SetSpecular(specular_mat);
AssetStore::Instance().GetMaterials().store(qui::Hash("PhongMaterial").value, std::shared_ptr<Material>(sphere_material));
Sphere *msphere = new Sphere();
msphere->SetMaterial("PhongMaterial");
msphere->SetCenter(glm::vec3(-100.f, -100.f, -100.f));
msphere->SetRadius(85.0);
msphere->baseColor = RGBColor::red;
this->AddObject(msphere);

Plane* plane = new Plane(glm::vec3(0.f, 50.f, -10.f), glm::vec3(0.f, -1.0f, 0.f));
plane->SetMaterial("PhongMaterial");

this->AddObject(plane);

outputFileName = "MultiObject.png";
