#include <iostream.h>

#include <conio.h>

#include <string.h>

#include <stdio.h>

#include <fstream.h>

#include <iomanip.h>


struct mon {

	char name[15]; 

	char sc; 

	int cnt;

	float sq; 

}; 

int main(void) {

	struct mon x; 

	int n, v;

	int i, j;

	int m; 

	char y_n;

	FILE* m_file;

	char filename[] = "monastir.bin";

	while (true) {

		cout << "Vibirite deistvie:" << "\n";

		cout << "1: sozdat fail" << "\n";

		cout << "2: dobavit dannie:" << "\n";

		cout << "3: vivesti dannie:" << "\n";

		cout << "4: sortirovka" << "\n";

		cout << "5: vixod" << "\n";

		cin >> v;

		if (v == 1) {

			m_file = fopen(filename, "w+");

			if (m_file == 0) {

				cout << "Sozdat file ne udalos!\n";

				getch();

				return(1);

			}

			fclose(m_file);

		}

		if (v == 2) {

			m_file = fopen(filename, "ab");

			if (m_file == 0) {

				cout << "otkrit file ne udalos!\n";

				getch();

				return(1);

			}

			int tt;

			do {

				tt = 0;


				cout << "Vvedite: nazvanie, shkolu, kol-vo, ploshad monastiria " << "\n";

				cin >> x.name;

				cin >> x.sc;

				cin >> x.cnt;

				cin >> x.sq;

				fwrite((char*)&x, sizeof(mon), 1, m_file);

				cout << "continue(y/n)?\n";

				cin >> y_n;

				if (y_n == 'y' || y_n == 'Y') tt = 1;

			} while (tt == 1);

			fclose(m_file);

		}

		if (v == 3) {

			m_file = fopen(filename, "r");

			cout << "------------------------------------------------------------\n";

			cout << "| monastiri |\n";

			cout << "|----------------------------------------------------------|\n";

			cout << "| nazvanie | shkola | Kolichestvo | Ploshad |\n";

			cout << "| | | monahov | zemel |\n";

			cout << "|---------------|----------|--------------|----------------|\n";

			fseek(m_file, 0, SEEK_END);

			n = ftell(m_file) / sizeof(mon);

			mon* mm = new mon[n];

			fseek(m_file, 0, SEEK_SET);


			fread(mm, sizeof(mon), n, m_file);

			fclose(m_file);

			for (i = 0; i < n; i++)

				cout << "|" << setw(15) << mm[i].name << "|" << setw(10) << mm[i].sc << "|" << setw(14) << mm[i].cnt << "|" << setw(16) << mm[i].sq << "|" << "\n";

			cout << "------------------------------------------------------------\n";

		}

		if (v == 4) {

			m_file = fopen(filename, "r");

			fseek(m_file, 0, SEEK_END);

			n = ftell(m_file) / sizeof(mon);

			mon* mm = new mon[n];

			fseek(m_file, 0, SEEK_SET);

			fread(mm, sizeof(mon), n, m_file);

			fclose(m_file);

			for (i = 0; i < n - 1; i++) {

				m = i;

				for (j = i + 1; j < n; j++)

					if (strcmp(mm[m].name, mm[j].name) > 0) m = j;

				if (m > i) {

					strcpy(x.name, mm[i].name);

					x.sc = mm[i].sc;

					x.cnt = mm[i].cnt;

					x.sq = mm[i].sq;

					strcpy(mm[i].name, mm[m].name);

					mm[i].sc = mm[m].sc;

					mm[i].cnt = mm[m].cnt;

					mm[i].sq = mm[m].sq;

					strcpy(mm[m].name, x.name);

					mm[m].sc = x.sc;

					mm[m].cnt = x.cnt;

					mm[m].sq = x.sq;

				}

			}

			fopen(filename, "w");

			fwrite(mm, sizeof(mon), n, m_file);

			fclose(m_file);

		}

		if (v == 5) {

			getch();

			return 1;

		}

	}