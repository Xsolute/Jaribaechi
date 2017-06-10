/*#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define STUDENT 20

using namespace std;

typedef struct Group {
public:
	int seat[4] = { 0 };
} Group;

void InputSeat(Group* A, Group* B, Group* C, Group* D, Group* E);

void ChangeSeat(Group* A, Group* B, Group* C, Group* D, Group* E);

void GroupSwap(Group* A, Group* B);

enum GroupList
{
	A, B, C, D, E
};

int main(int argc, char** argv) {
	srand(time(NULL));

	Group A, B, C, D, E;

	InputSeat(&A, &B, &C, &D, &E);
	ChangeSeat(&A, &B, &C, &D, &E);

	return 0;
}

void InputSeat(Group* A, Group* B, Group* C, Group* D, Group* E) {
	char input;

	cout << "�ڸ���ġ ���α׷�" << endl;
	cout << "�Է�/��� ���� : \n����������\n�� 1�� 2��\n����������\n�� 3�� 4��\n����������" << endl;
	cout << "<-> 1 2 3 4\n" << endl;
	cout << "��� ��� : \nA   B\nC D E\n" << endl;

	for (;;) {

		cout << "���� �ڸ��� �Է��Ͽ� �ֽʽÿ�. (A��Һ��� E��ұ��� �л��� ��ȣ) " << endl;

		for (int i = GroupList::A; i <= GroupList::E; i++) {

			switch (i) {
			case GroupList::A:
				cout << "A��� �Է� : " << endl;
				break;
			case GroupList::B:
				cout << "B��� �Է� : " << endl;
				break;
			case GroupList::C:
				cout << "C��� �Է� : " << endl;
				break;
			case GroupList::D:
				cout << "D��� �Է� : " << endl;
				break;
			case GroupList::E:
				cout << "E��� �Է� : " << endl;
				break;
			}

			for (int j = 0; j < 4; j++) {

				switch (i) {
				case GroupList::A:
					cin >> A->seat[j];
					break;
				case GroupList::B:
					cin >> B->seat[j];
					break;
				case GroupList::C:
					cin >> C->seat[j];
					break;
				case GroupList::D:
					cin >> D->seat[j];
					break;
				case GroupList::E:
					cin >> E->seat[j];
					break;
				}

			}

		}

		cout << "�� �ڸ��� �´��� Ȯ���ϰ� �´ٸ� y(Y)��, �ƴϸ� �̿��� ���ڸ� �Է��Ͻʽÿ�.\n" << endl;

		for (int i = GroupList::A; i <= GroupList::E; i++) {

			switch (i) {
			case GroupList::A:
				cout << "A���" << endl;
				break;
			case GroupList::B:
				cout << "B���" << endl;
				break;
			case GroupList::C:
				cout << "C���" << endl;
				break;
			case GroupList::D:
				cout << "D���" << endl;
				break;
			case GroupList::E:
				cout << "E���" << endl;
				break;
			}

			for (int j = 0; j < 4; j++) {

				switch (i) {
				case GroupList::A:
					cout << A->seat[j] << " ";
					break;
				case GroupList::B:
					cout << B->seat[j] << " ";
					break;
				case GroupList::C:
					cout << C->seat[j] << " ";
					break;
				case GroupList::D:
					cout << D->seat[j] << " ";
					break;
				case GroupList::E:
					cout << E->seat[j] << " ";
					break;
				}

			}

			cout << endl;

		}

		cin >> input;

		if (input == 'Y' || input == 'y') goto INPUT_EXIT;
		else {
			cout << "�ڸ��� ���Է��Ͻʽÿ�." << endl;
			continue;
		}
	}

INPUT_EXIT:
	cout << "���ο� �ڸ���ġ�� �����մϴ�.\n" << endl;
	return;
}

void ChangeSeat(Group* A, Group* B, Group* C, Group* D, Group* E) {
	char GroupPlace[2][3] = { 'A', 'X', 'B', 'C', 'D', 'E' };

	cout << "���� ��� ��ġ : " << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << GroupPlace[i][j] << " ";
		}
		cout << endl;
	}

	cout << "D���(��� ���)�� ��ġ�� ��ȯ�մϴ�." << endl;
	
	switch ((rand() % 5) + 1) {
	case 1:
		cout << "���� ��� : D��Ұ� A����� ��ġ�� ��ȯ�մϴ�." << endl;
		GroupSwap(D, A);
		GroupPlace[0][0] = 'D';
		GroupPlace[1][1] = 'A';
		break;
	case 2:
		cout << "���� ��� : D��Ұ� B����� ��ġ�� ��ȯ�մϴ�." << endl;
		GroupSwap(D, B);
		GroupPlace[0][2] = 'D';
		GroupPlace[1][1] = 'B';
		break;
	case 3:
		cout << "���� ��� : D��Ұ� C����� ��ġ�� ��ȯ�մϴ�." << endl;
		GroupSwap(D, C);
		GroupPlace[1][0] = 'D';
		GroupPlace[1][1] = 'C';
		break;
	case 4:
		cout << "���� ��� : D����� ��ġ�� ��ȯ���� �ʽ��ϴ�." << endl;
		break;
	case 5:
		cout << "D��Ұ� E����� ��ġ�� ��ȯ�մϴ�." << endl;
		GroupSwap(D, E);
		GroupPlace[1][2] = 'D';
		GroupPlace[1][1] = 'E';
		break;
	}

	cout << "D��� ��ġ ��ȯ ��� : " << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << GroupPlace[i][j] << " ";
		}
		cout << endl;
	}
	
}

void GroupSwap(Group* A, Group* B) {
	Group* temp;
	temp = A;
	A = B;
	B = temp;
	return;
} */