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

outputFileName = "Blender.png";