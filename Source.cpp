#include <iostream>
#include <string>
using namespace std;	

class tablet {

public:

	bool tabletGreeting()
	{
		/* Greet clients walking in the door
		An android / apple tablet on a stand is located right as they walk in the building
		Present them with a QR Code and a brief introduction as to what our app does
	*/

		cout << " Welcome to Our Lounge " << endl;
		cout << " Company logo and splash screen here" << endl;
		cout << " Tap here to place an order now!" << endl;

		bool doAgain = true;
		
		bool continueOnTablet = false;

		while (doAgain == true)
		{


			cout << " Would you like to place the order on this tablet or your phone ? " << endl;
			string decision;
			cin >> decision;

			if (decision == "phone") {
				cout << "Download via QR code now! ";
				cout << endl << endl << " QR CODE HERE" << endl;
				doAgain = false;
				return false;
			}

			else if (decision == "tablet")
			{
				cout << endl << "Okay, lets place your order here! " << endl;
				doAgain = false;
				continueOnTablet = true;
				return true;
			}
			/*User taps on the screen and is now taken to a QR code screen*/

			else {
				cout << " Please choose either phone or tablet " << endl;
			}

		}
		

		/*
			user is redirected to google play store and downloads the app there
		*/
	}

};


class orderFood
{

public:

	void addtoCart(orderFood foodObject);
	void removeFromCart(orderFood foodObject);



	void getFoodList() {
		
		string foodOptions[] = { "Chipotle", "Pizza Hut", "Red Robins", "McDonalds" };
		
		cout << " The food options here are: " << endl;
		// Retrieve list of food options from backend web server DB
		for (int i = 0; i < sizeof(foodOptions) / sizeof(foodOptions[0]); i++)
		{
			cout << foodOptions[i] << endl;
		}
	}



};

class checkout
{
	friend int main();
public:

	void getCart();
	void submitOrder();

private:

	bool connectToCheckoutService();
	bool authenticatePayment();

};

class receiver
{
public:
	void receiveOrder(orderFood object);
	void orderPending();
	void orderComplete(orderFood object);
};





int main()
{
	tablet myTablet;
	orderFood cart1;
	orderFood item1;

	checkout process1;


	receiver restaurant1;

	

	bool determine = myTablet.tabletGreeting();

	if (determine) {
		item1.getFoodList();
		//user will then go through the process of ordering their food from the restaurants
		//all this data is stored on our web server db which our app connects to to display restaurant selection and items
		cart1.addtoCart(item1);

		//customer then submits order
		process1.getCart();
		process1.submitOrder();

		//using third party secure encrypted https connect to payment platform
		process1.connectToCheckoutService();
		process1.authenticatePayment();


		//order is then sent to receiving tablet in restaurant
		restaurant1.receiveOrder(cart1);
		//let client know that the order is being prepared
		restaurant1.orderPending();
		//When order is complete send push notification to client
		restaurant1.orderComplete(cart1);
	}
	
	system("PAUSE");
}