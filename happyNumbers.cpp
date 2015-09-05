#include <iostream>
#include <set>
using namespace std;
 
int main()
{
	set <int> numberSet;
	int numberOfIntegers = 0;
	int ans = 0;
	int x;
	int lastDigit;
	for (int i = 0; i < 10; i++) {   // The program was designed to receive 10 input numbers
		numberSet.clear();
		cin >> x;
		numberSet.insert(x);
		numberOfIntegers = 0;
		ans = 0;
		bool repeat = true;
		while (repeat) {
			while (x > 9){
				lastDigit = x % 10;
				ans = ans + (lastDigit * lastDigit);
				x = x/10;
			}
			lastDigit = x;
			ans = ans + (lastDigit * lastDigit);
			if (ans == 1){
				cout << "happy: number of integers before happiness = " << numberOfIntegers+1 <<endl;
				repeat = false;
			}
			else if (numberSet.insert(ans).second) {
				cout << ans << endl; 
				x = ans;
				numberOfIntegers++;
				ans = 0;
			}
			else {
				cout << "unhappy: number of integers before unhappiness = "<< numberOfIntegers+1 << endl;
				repeat = false;
			}
		}
	}
	return 0;
}