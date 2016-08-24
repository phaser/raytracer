#pragma once
float ambient_kd = 0.15;

vp = new ViewPlane();
vp->SetWidth(640)
.SetHeight(480)
.SetPixelSize(1.f);
vp->SetFocalDistance(800.f);
uint16_t num_samples = 64;
LOG(INFO) << "Jitter Sampler with " << num_samples << " samples per pixel.";
vp->SetSamplerPtr(new Jitter(num_samples));
imgBuffer = new ImageBufferPNG();
imgBuffer->AllocImage(vp->GetWidth(), vp->GetHeight());
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
ambient_mat->SetCd(RGBColor(glm::vec3(202.f/255.f, 225.f/255.f, 1.f)));
ambient_mat->SetKd(ambient_kd);
diffuse_mat->SetCd(RGBColor(glm::vec3(202.f/255.f, 225.f/255.f, 1.f)));
sphere_material->SetAmbient(ambient_mat);
sphere_material->SetDiffuse(diffuse_mat);
sphere_material->SetSpecular(specular_mat);
AssetStore::Instance().GetMaterials().store(qui::Hash("PhongMaterial").value, std::shared_ptr<Material>(sphere_material));

size_t sz = 5;
for (int i = 0; i < sz; ++i)
{
    Sphere *msphere = new Sphere();
    msphere->SetMaterial("PhongMaterial");
    msphere->SetCenter(glm::vec3(-200.f * glm::cos((glm::pi<float>() * (i+1)) / (sz + 1))
                                 , -100.f
                                 , -200.f * glm::sin((glm::pi<float>() * (i+1)) / (sz + 1))));
    msphere->SetRadius(85.0);
    msphere->baseColor = RGBColor::red;
    this->AddObject(msphere);
}

sphere_material = new Phong();
ambient_mat = new Lambertian();
diffuse_mat = new Lambertian();
specular_mat = new GlossySpecular();
ambient_mat->SetCd(RGBColor(glm::vec3(0.3f, 0.3f, 0.3f)));
ambient_mat->SetKd(ambient_kd);
diffuse_mat->SetCd(RGBColor(glm::vec3(0.3f, 0.3f, 0.3f)));
sphere_material->SetAmbient(ambient_mat);
sphere_material->SetDiffuse(diffuse_mat);
sphere_material->SetSpecular(specular_mat);
sphere_material->SetCheckered(true);
AssetStore::Instance().GetMaterials().store(qui::Hash("PlaneMaterial").value, std::shared_ptr<Material>(sphere_material));

Plane* plane = new Plane(glm::vec3(0.f, 50.f, -10.f), glm::vec3(0.f, -1.0f, 0.f));
plane->SetMaterial("PlaneMaterial");
this->AddObject(plane);

outputFileName = "DancingSpheres.png";

