#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int amount = 0;
struct VehicleList {
	string carBrand;
	string brandModel;
	int manufacturingYear=0;
	string carType;
	string motorType;
	double marketValue=0;
} Cars[150];

void InFile() {
	string cB;
	string bM;
	int mY;
	string cT;
	string mT;
	double mV;
	fstream fin("CarsList.txt", ios::in);
	if (fin.is_open()) {
			while (fin >> cB >> bM >> mY >> cT >> mT >> mV) {
				Cars[amount].carBrand = cB;
				Cars[amount].brandModel = bM;
				Cars[amount].manufacturingYear = mY;
				Cars[amount].carType = cT;
				Cars[amount].motorType = mT;
				Cars[amount].marketValue = mV;
				amount++;
			}
		fin.close();
	}
};

void OutFile(string file, int first, int last) {
	fstream fout(file, ios::out);
	 int i = first;
	 if (fout.is_open()) {
		while (i <= last) {
				fout << Cars[i].carBrand << ' ' << Cars[i].brandModel << ' ' << Cars[i].manufacturingYear <<
					' ' << Cars[i].carType << ' ' << Cars[i].motorType << ' ' << Cars[i].marketValue << '\n';
				i++;
		}
			fout.close();
	 }
}

void OutFile(string file) {
		string cB;
		string bM;
		int mY;
		string cT;
		string mT;
		double mV;
		cout << "  Введите марку автомобиля" << '\n';
		cin >> cB;
		cout << "  Введите модель введенной марки" << '\n';
		cin >> bM;
		cout << "  Укажите год выпуска" << '\n';
		cin >> mY;
		cout << "  Укажите тип кузова автомобиля" << '\n';
		cin >> cT;
		cout << "  Укажите тип мотора" << '\n';
		cin >> mT;
		cout << "  Введите рыночную стоимость (в тыс.долл)" << '\n';
		cin >> mV;
		fstream fout(file, ios::app);
		if (fout.is_open()) {
			fout << '\n' << ' ' << cB << ' ' << bM << ' ' << mY << ' ' << cT << ' ' << mT << ' ' << mV;
		}
		fout.close();
}

void PrintList(int start, int end) {
	cout << '\n' << left << setw(5) << "  №" << setw(15) << "  Марка"
		<< setw(15) << "  Moдель"
		<< setw(10) << "  Год"
		<< setw(15) << "  Тип"
		<< setw(15) << "  Двигатель"
		<< setw(20) << "  Рыночная стоимость (тыс. долл)"
		<< endl;
	cout << "  " << setfill('=') << setw(105) << "" << setfill(' ') << '\n';
	for (int i = start; i < end;i++) {
		cout << "  " << left << setw(5) << i + 1 << setw(15) << Cars[i].carBrand << setw(15) << Cars[i].brandModel
			<< setw(10) << Cars[i].manufacturingYear
			<< setw(15) << Cars[i].carType
			<< setw(15) << Cars[i].motorType
			<< fixed << setprecision(2) << setw(20) << Cars[i].marketValue
			<< '\n';
	}
};

void BubbleSort() {
	VehicleList temp;
	for (int i = 1;i < amount;i++) {
		for (int j = 0;j < amount - i;j++) {
			if (Cars[j].marketValue > Cars[j + 1].marketValue) {
				temp = Cars[j + 1];
				Cars[j + 1] = Cars[j];
				Cars[j] = temp;
			}
		}
	}
};

int Partition(int left, int right) {
	VehicleList temp;
	VehicleList pivot = Cars[(left+right)/2];
	int i = left;
	int j = right;
	while (true) {
		while (Cars[i].marketValue < pivot.marketValue) {
			i++;
		}
		while (Cars[j].marketValue > pivot.marketValue) {
			j--;
		}
		if (i >= j) {
			return j;
		}
		temp = Cars[i];
		Cars[i] = Cars[j];
		Cars[j] = temp;
		i++;
		j--;
	}
}

void QuickSort(int left, int right) {
	if (left < right) {
	
		int pi = Partition(left, right);

		QuickSort(left, pi);
		QuickSort(pi + 1, right);
	}
}

int BinarySearch(int left, int right, double key) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (right-left<=1) {
			return mid;
		} else if (Cars[mid].marketValue > key) {
			return BinarySearch(left, mid - 1, key);
		}
		else if (Cars[mid].marketValue < key) {
			return BinarySearch(mid + 1, right, key);
		}
		else if (Cars[mid].marketValue == key) {
			return mid;
		}
	}
}

int IndexAdjustment(int index,double key,bool bound) {
	if (!bound) {
		for (int i = index - 3; i <= index + 3;i++) {
			if (Cars[i + 1].marketValue > key) {
				return i + 1;
			}
			if (Cars[i + 1].marketValue == key) {
				return i+1;
			}
		}
	}
	else {
		for (int i = index - 3; i <= index + 3;i++) {
			if (Cars[i + 1].marketValue > key) {
				return i;
			}
			if (Cars[i + 1].marketValue == key) {
				return i+1;
			}
		}
	}
}

int LinearSearch(double key) {
	for (int i = 0; i < amount;i++) {
		if (Cars[i].marketValue == key) {
			return i;
			break;
		}
	}
	return -1;
}

void AddElement(){
	cout << "  Введите марку автомобиля" << '\n';
	cin >> Cars[amount].carBrand;
	cout << "  Введите модель введенной марки" << '\n';
	cin >> Cars[amount].brandModel;
	cout << "  Укажите год выпуска" << '\n';
	cin >> Cars[amount].manufacturingYear;
	cout << "  Укажите тип кузова автомобиля" << '\n';
	cin >> Cars[amount].carType;
	cout << "  Укажите тип мотора" << '\n';
	cin >> Cars[amount].motorType;
	cout << "  Введите рыночную стоимость (в тыс.долл)" << '\n';
	cin >> Cars[amount].marketValue;
	amount++;
}

void DeleteElement(int number) {
	int numberIn = number - 1;
	if (numberIn < 0 || numberIn >= amount) {
		return;
	}
	for (int i = numberIn; i < amount - 1; i++) {
		Cars[i] = Cars[i + 1];
	}
	amount--;

}

void СlearAndRefreshConsoleUnix()
{
	cout << "\033c";
}

void MainMenu() {
   cout << " +--------------------------------------------------------------+" << '\n'
		<< " | Курсовая работа. Структура списка товаров автозавода.        |" << '\n'
		<< " | Римонт Елисей, ФИТУ ИИ, Группа 321702                        |" << '\n'
		<< " +--------------------------------------------------------------+" << '\n' << '\n' << '\n';

	cout << "  Выберите операцию, которую хотите выполнить (1 - 10, нажмите 0, чтобы завершить программу) :" << '\n'
		<< "  1. Вывести весь список товаров автозавода" << '\n'
		<< "  2. Отсортировать список по ключу методом пузырьковой сортировки" << '\n'
		<< "  3. Отсортировать список по ключу методом быстрой сортировки" << '\n'
		<< "  4. Найти элемент в списке методом прямого поиска" << '\n'
		<< "  5. Найти элемент в списке методом двоичного поиска" << '\n'
		<< "  6. Добавить элемент в список" << '\n'
		<< "  7. Удалить элемент из списка" << '\n'
		<< "  8. Добавить элемент в начальный файл" << '\n'
		<< "  9. Запись отсортированного списка в файл" << '\n'
		<< "  10.Вывод и запись задания в файл" << '\n' << '\n';
}

int main()
{	setlocale(LC_ALL, "Russian");
		InFile();
		MainMenu();
		int option = -1;
		while (option != 0) {
		cin >> option;
			СlearAndRefreshConsoleUnix();
			MainMenu();
		switch (option)
		{
		case 1:
			PrintList(0, amount);
			break;
		case 2:
			BubbleSort();
			break;
		case 3:
			QuickSort(0,amount-1);
			break;
		case 4:
			double value;
			cout << "Введите рыночную стоимость элемента который хотите найти:" << '\n';
			cin >> value;
			PrintList(LinearSearch(value), LinearSearch(value)+1);
			break;
		case 5:
			cout << "Введите рыночную стоимость элемента который хотите найти:" << '\n';
			cin >> value;
			QuickSort(0, amount - 1);
			PrintList(BinarySearch(0, amount - 1, value), BinarySearch(0, amount - 1, value) + 1);
			break;
		case 6:
			cout << "Введите элемент который хотите добавить:" << '\n';
			AddElement();
			break;
		case 7:
			cout << "Введите номер элемента который хотите удалить:" << '\n';
			int num;
			cin >> num;
			DeleteElement(num);
			break;
		case 8:
			cout << "Введите элемент который хотите добавить:" << '\n';
			OutFile("CarsList.txt");
			break;
		case 9:
			QuickSort(0, amount - 1);
			OutFile("SortFile.txt",0,amount-1);
			break;
		case 10:
			QuickSort(0, amount - 1);
			PrintList(IndexAdjustment(BinarySearch(0, amount - 1, 20.0), 20.0, 0), IndexAdjustment(BinarySearch(0, amount - 1, 50.0), 50.0, 1)+1);
			OutFile("TaskFile.txt", IndexAdjustment(BinarySearch(0, amount - 1, 20.0), 20.0, false), IndexAdjustment(BinarySearch(0, amount - 1, 50.0), 50.0, true));
			break;
		case 0:
			cout << "Программа завершена.";
			return 0;
			break;
		default: 
			cout << "Нет такой операции." << '\n';
			break;
		}
		
	}
	return 0;
}

