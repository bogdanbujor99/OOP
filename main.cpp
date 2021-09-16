#include "Mercedes.h"
#include "Toyota.h"
#include "Ford.h"
#include "Dacia.h"
#include "Mazda.h"
#include "Circuit.h"

int main()
{
	Circuit c;
	c.SetLenght(1000);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Mazda());
	c.AddCar(new Dacia());
	c.AddCar(new Mercedes());
	c.AddCar(new Toyota());
	c.AddCar(new Ford());
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();
}
