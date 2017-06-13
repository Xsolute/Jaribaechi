#include "JRBCH.h"

int main(int argc, char** argv) {
	int OriginalSeat[GROUP][GROUP_STUDENT] = { 0 }; // ���� �ڸ�
	int RandomizedSeat[GROUP][GROUP_STUDENT] = { 0 }; // ����ȭ�� �ڸ�
	bool CheckExistNum[STUDENT] = { false }; // �ߺ� Ȯ�� �迭

	char input; // �ƹ� Ű�� �����ʽÿ� �Է�
	int randomize_count = 0; // ���� Ƚ��

	srand((unsigned)time(NULL)); // ���� ��� �ʱ�ȭ

	cout << "�ڸ���ġ ���α׷�" << endl;
	cout << "�Է�/��� ���� : \n����������\n�� 1�� 2��\n����������\n�� 3�� 4��\n����������" << endl;
	cout << "<-> 1 2 3 4\n" << endl;
	cout << "��� ��� : \nA   B\nC D E\n" << endl;

	for (;;) {

		cout << "���� �ڸ��� �Է��Ͽ� �ֽʽÿ�. (A��Һ��� E��ұ��� �л��� ��ȣ) " << endl;

		for (int i = 0; i < GROUP; i++) { // GROUP ����ŭ �ݺ�

			switch (i) { // �Է� Ȯ��
			case 0:
				cout << "A��� �Է� : " << endl;
				break;
			case 1:
				cout << "B��� �Է� : " << endl;
				break;
			case 2:
				cout << "C��� �Է� : " << endl;
				break;
			case 3:
				cout << "D��� �Է� : " << endl;
				break;
			case 4:
				cout << "E��� �Է� : " << endl;
				break;
			}

			for (int j = 0; j < GROUP_STUDENT; j++) { // ����� �л� ����ŭ �Է�

				cin >> OriginalSeat[i][j];

			}

		}

		cout << "�� �ڸ��� �´��� Ȯ���ϰ� �´ٸ� y(Y)��, �ƴϸ� �̿��� ���ڸ� �Է��Ͻʽÿ�.\n" << endl;

		cout << "����������          ����������" << endl;
		cout << "��" << ((OriginalSeat[0][0] / 10 != 0) ? "" : " ") << OriginalSeat[0][0] << "��" << ((OriginalSeat[0][1] / 10 != 0) ? "" : " ") << OriginalSeat[0][1] << "��" << "          ��" << ((OriginalSeat[1][0] / 10 != 0) ? "" : " ") << OriginalSeat[1][0] << "��" << ((OriginalSeat[1][1] / 10 != 0) ? "" : " ") << OriginalSeat[1][1] << "��" << endl;
		cout << "����������          ����������" << endl;
		cout << "��" << ((OriginalSeat[0][2] / 10 != 0) ? "" : " ") << OriginalSeat[0][2] << "��" << ((OriginalSeat[0][3] / 10 != 0) ? "" : " ") << OriginalSeat[0][3] << "��" << "          ��" << ((OriginalSeat[1][2] / 10 != 0) ? "" : " ") << OriginalSeat[1][2] << "��" << ((OriginalSeat[1][3] / 10 != 0) ? "" : " ") << OriginalSeat[1][3] << "��" << endl;
		cout << "����������          ����������" << endl;
		cout << "������������������������������" << endl;
		cout << "��" << ((OriginalSeat[2][0] / 10 != 0) ? "" : " ") << OriginalSeat[2][0] << "��" << ((OriginalSeat[2][1] / 10 != 0) ? "" : " ") << OriginalSeat[2][1] << "����" << ((OriginalSeat[3][0] / 10 != 0) ? "" : " ") << OriginalSeat[3][0] << "��" << ((OriginalSeat[3][1] / 10 != 0) ? "" : " ") << OriginalSeat[3][1] << "����" << ((OriginalSeat[4][0] / 10 != 0) ? "" : " ") << OriginalSeat[4][0] << "��" << ((OriginalSeat[4][1] / 10 != 0) ? "" : " ") << OriginalSeat[4][1] << "��" << endl;
		cout << "������������������������������" << endl;
		cout << "��" << ((OriginalSeat[2][2] / 10 != 0) ? "" : " ") << OriginalSeat[2][2] << "��" << ((OriginalSeat[2][3] / 10 != 0) ? "" : " ") << OriginalSeat[2][3] << "����" << ((OriginalSeat[3][2] / 10 != 0) ? "" : " ") << OriginalSeat[3][2] << "��" << ((OriginalSeat[3][1] / 10 != 0) ? "" : " ") << OriginalSeat[3][3] << "����" << ((OriginalSeat[4][2] / 10 != 0) ? "" : " ") << OriginalSeat[4][2] << "��" << ((OriginalSeat[4][3] / 10 != 0) ? "" : " ") << OriginalSeat[4][3] << "��" << endl;
		cout << "������������������������������" << endl;

		cin >> input;

		if (input == 'y' || input == 'Y') goto INPUT_EXIT; // �Է� Ȯ��
		else {
			cout << "�ڸ��� ���Է��Ͻʽÿ�." << endl;
			continue;
		}
	}
	
INPUT_EXIT:

	fflush(stdin);
	cout << "���ο� �ڸ���ġ�� �����մϴ�. �ƹ� Ű�� �����ʽÿ�.\n" << endl;
	input = getch();

	// �ڸ���ġ ����

RERANDOMIZE:

	for (int i = 0; i < GROUP; i++) {
		for (int j = 0; j < GROUP_STUDENT; ) {
			int tempNum = randomize();
			if(CheckExistNum[tempNum] == false) { // ������ �ߺ����� �ʰ� ��
				CheckExistNum[tempNum] = true;
				RandomizedSeat[i][j] = tempNum+1;
				++j;
			}
		}
	} // �ڸ� ����ȭ �Ϸ�, ���� �ڸ��� ���� ������ Ȯ��

	for (int i = 0; i < GROUP; i++) {
		for (int j = 0; j < GROUP_STUDENT; j++) {
			if (RandomizedSeat[i][j] == OriginalSeat[i][0] ||
				RandomizedSeat[i][j] == OriginalSeat[i][1] ||
				RandomizedSeat[i][j] == OriginalSeat[i][2] ||
				RandomizedSeat[i][j] == OriginalSeat[i][3]) // ����ȭ �ڸ��� ���� �ڸ��� ���� ����� ��
			{
				for (int k = 0; k < STUDENT; k++) {
					CheckExistNum[k] = false;
				}
				++randomize_count;
				goto RERANDOMIZE; // �緣��ȭ
			}
		}
	}
	
	// �ڸ���ġ �Ϸ�, ���

	fflush(stdin);
	cout << "�ڸ���ġ�� �Ϸ�Ǿ����ϴ�. �ƹ� Ű�� �����ʽÿ�." << endl;
	input = getch();

	cout << "����������          ����������" << endl;
	cout << "��" << ((RandomizedSeat[0][0] / 10 != 0) ? "" : " ") << RandomizedSeat[0][0] << "��" << ((RandomizedSeat[0][1] / 10 != 0) ? "" : " ") << RandomizedSeat[0][1] << "��" << "          ��" << ((RandomizedSeat[1][0] / 10 != 0) ? "" : " ") << RandomizedSeat[1][0] << "��" << ((RandomizedSeat[1][1] / 10 != 0) ? "" : " ") << RandomizedSeat[1][1] << "��" << endl;
	cout << "����������          ����������" << endl;
	cout << "��" << ((RandomizedSeat[0][2] / 10 != 0) ? "" : " ") << RandomizedSeat[0][2] << "��" << ((RandomizedSeat[0][3] / 10 != 0) ? "" : " ") << RandomizedSeat[0][3] << "��" << "          ��" << ((RandomizedSeat[1][2] / 10 != 0) ? "" : " ") << RandomizedSeat[1][2] << "��" << ((RandomizedSeat[1][3] / 10 != 0) ? "" : " ") << RandomizedSeat[1][3] << "��" << endl;
	cout << "����������          ����������" << endl;
	cout << "������������������������������" << endl;
	cout << "��" << ((RandomizedSeat[2][0] / 10 != 0) ? "" : " ") << RandomizedSeat[2][0] << "��" << ((RandomizedSeat[2][1] / 10 != 0) ? "" : " ") << RandomizedSeat[2][1] << "����" << ((RandomizedSeat[3][0] / 10 != 0) ? "" : " ") << RandomizedSeat[3][0] << "��" << ((RandomizedSeat[3][1] / 10 != 0) ? "" : " ") << RandomizedSeat[3][1] << "����" << ((RandomizedSeat[4][0] / 10 != 0) ? "" : " ") << RandomizedSeat[4][0] << "��" << ((RandomizedSeat[4][1] / 10 != 0) ? "" : " ") << RandomizedSeat[4][1] << "��" << endl;
	cout << "������������������������������" << endl;
	cout << "��" << ((RandomizedSeat[2][2] / 10 != 0) ? "" : " ") << RandomizedSeat[2][2] << "��" << ((RandomizedSeat[2][3] / 10 != 0) ? "" : " ") << RandomizedSeat[2][3] << "����" << ((RandomizedSeat[3][2] / 10 != 0) ? "" : " ") << RandomizedSeat[3][2] << "��" << ((RandomizedSeat[3][3] / 10 != 0) ? "" : " ") << RandomizedSeat[3][3] << "����" << ((RandomizedSeat[4][2] / 10 != 0) ? "" : " ") << RandomizedSeat[4][2] << "��" << ((RandomizedSeat[4][3] / 10 != 0) ? "" : " ") << RandomizedSeat[4][3] << "��" << endl;
	cout << "������������������������������" << endl;

	cout << "�ڸ�/�� �ߺ��� ���ϱ� ���� RERANDOMIZE Ƚ�� : " << randomize_count << "ȸ" << endl << endl << "�ڸ���ġ ���α׷��� �����մϴ�. �ƹ� Ű�� �����ʽÿ�." << endl;
	input = getch();
	return 0;
}

int randomize(void) {
	return (rand() % 20); // ���� �Լ�
}