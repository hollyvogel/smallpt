// low level libraries included first


#include <Scene.h>

#include <Util.h>
#include <HaltonSampler.h>

#include <SamplerAbstract.h>
#include<PathIntegrator.h>
#include <Film.h>
#include <Render.h>
#include <MaterialInterface.h>
#include <BRDF.h>
#include <Sphere.h>


//unsigned int  width=200, height=700;


//inline double clamp(double x){return x<0 ? 0 : x>1 ? 1 : x;}
//inline int toInt(double x){return int(pow(clamp(x),1/2.2) * 255 +.5);}




int main(){


//Image image(width, height);
//Image image(width, height);
//Point2i resolution(width,height);
//image.setResolution(resolution);

std::shared_ptr<Film> image(new Film());
std::shared_ptr<Data> options(new Data);



int width = options->res_x;
int height = options->res_y;

Point2i resolution(width,height);
image->setResolution(resolution);


//std::shared_ptr<PathIntegrator> pathtracer(new PathIntegrator());
std::shared_ptr<Scene> scene(new Scene());


//std::shared_ptr<Material>lambert(new Material(E));
std::shared_ptr<MaterialInterface>brdf(new BRDF());

std::shared_ptr<Material>lightSource(new Material(emission, Colour3f(0,0,0),Colour3f(1000.f,1000.f,1000.f)));


std::shared_ptr<Material>middle_material (new Material(diffuse, Colour3f(25.f,25.f,75.f),Colour3f(0,0,0)));
std::shared_ptr<Material>right_material (new Material(diffuse, Colour3f(75.f,25.f,75.f),Colour3f(0,0,0)));
std::shared_ptr<Material>left_material (new Material(diffuse, Colour3f(75.f,25.f,25.f),Colour3f(0,0,0)));
//std::shared_ptr<Material>material(new Material(brdf));
std::shared_ptr<Material>top_wall (new Material(diffuse, Colour3f(75.f,75.f,75.f),Colour3f(0,0,0)));
std::shared_ptr<Material>bottom_wall (new Material(diffuse, Colour3f(100.f,25.f,25.f),Colour3f(0,0,0)));
std::shared_ptr<Material>left_wall (new Material(diffuse, Colour3f(25.f,100.f,25.f),Colour3f(0,0,0)));
std::shared_ptr<Material>right_wall (new Material(diffuse, Colour3f(100.f,25.f,25.f),Colour3f(0,0,0)));
std::shared_ptr<Material>back_wall (new Material(diffuse, Colour3f(100.f,25.f,25.f),Colour3f(0,0,0)));

//-------------------------------------------------------------------------------------------------------
middle_material->setMaterial(brdf);
right_material->setMaterial(brdf);
left_material->setMaterial(brdf);
top_wall->setMaterial(brdf);
bottom_wall->setMaterial(brdf);
lightSource->setMaterial(brdf);

back_wall->setMaterial(brdf);
//-------------------------------------------------------------------------------------------------------
std::shared_ptr<Sphere> middle(new Sphere);
middle->setRadius(1);
middle->setPosition(Vector3f(0,0,-15));
middle->setMaterial(middle_material);
middle->getMaterial()->setType(diffuse);
scene->addObject(middle);



std::shared_ptr<Sphere> right(new Sphere);
right->setRadius(1);
right->setPosition(Vector3f(-5,.2,-24));
right->setMaterial(right_material);
scene->addObject(right);

std::shared_ptr<Sphere> light(new Sphere);
light->setRadius(100);
light->setPosition(Vector3f(0,130,-14));
light->setMaterial(lightSource);
scene->addObject(light);

//std::shared_ptr<Sphere> light2(new Sphere);
//light2->setRadius(0.1);
//light2->setPosition(Vector3f(-0.6,0,-13));
//light2->setMaterial(lightSource);
//scene->addObject(light2);



// -----------------------------------------------------

 std::shared_ptr<Sphere> bottom_(new Sphere);
 bottom_->setRadius(1000);
 bottom_->setPosition(Vector3f(0,-1001,0));
 bottom_->setMaterial(bottom_wall);
scene->addObject(bottom_);

//std::shared_ptr<Sphere> top_(new Sphere);
//top_->setRadius(1000);
//top_->setPosition(Vector3f(0,1006,0));
//top_->setMaterial(top_wall);
//scene->addObject(top_);

//std::shared_ptr<Sphere> left_(new Sphere);
//left_->setRadius(1000);
//left_->setPosition(Vector3f(-1000,0,0));
//left_->setMaterial(left_wall);
//scene->addObject(left_);

//std::shared_ptr<Sphere> right_(new Sphere);
//right_->setRadius(1000);
//right_->setPosition(Vector3f(1000,0,0));
//right_->setMaterial(right_wall);
//scene->addObject(right_);

//std::shared_ptr<Sphere> back_(new Sphere);
//back_->setRadius(1000);
//back_->setPosition(Vector3f(0,0,-1000));
//back_->setMaterial(back_wall);
//scene->addObject(back_);

// std::shared_ptr<Sphere> top_(new Sphere);
//top_->setRadius(1e5);
//top_->setPosition(Vector3f(0,1e5,0));
//top_->setMaterial(top_wall);
//scene->addObject(top_);




std::shared_ptr<Camera> camera(new Camera);


camera->setWidth(width);
camera->setHeight(height);

scene->addCamera(camera);
scene->addMaterial(middle_material);
scene->addMaterial(right_material);
scene->addMaterial(left_material);

//scene->addMaterial(top_material);
//scene->addMaterial(bottom_material);
//scene->addMaterial(back_material);

srand(time(NULL));


std::shared_ptr<Render> renderScene(new Render);
renderScene->getScene(scene);
renderScene->getOptions(options);
renderScene->render();




return EXIT_SUCCESS;

}
