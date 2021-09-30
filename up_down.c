#include <stdio.h>
#include <Windows.h>
#include <time.h>

int main()
{
	int game_mode;
	unsigned int Que, Ans = 0;
	int running = 1;
	int i = 0;

	while (running)
	{
		printf("UP & DOWN 게임에 오신 것을 환영합니다!\n");
		printf("=== 1 : 친구 대전 ===\n");
		printf("=== 2 : A  I 대전 ===\n");
		printf("게임 모드를 입력해주세요 : ");
		scanf_s("%d", &game_mode);
		if (game_mode < 1 || game_mode > 2)
		{
			system("cls");
			printf("올바른 게임 모드 값을 입력해주세요.");
			Sleep(2000);
			system("cls");
			continue;
		}
		break;
	}
	system("cls");

	switch (game_mode)
	{
	case 1:
		while (running)
		{
			printf("정답이 될 1 ~ 100 사이의 숫자를 입력하세요 : ");
			scanf_s("%d", &Ans);

			if (Ans < 1 || Ans > 100)
			{
				system("cls");
				printf("1 ~ 100 사이의 숫자만 입력해주세요.");
				Sleep(2000);
				system("cls");
			}
			else
				running = 0;
		}

		running = 1;
		printf("이제 친구에게 넘겨주세요!");
		Sleep(1000);
		system("cls");

		// event_loop
		while (running)
		{
			printf("남은 기회 %d번\n", 5 - i);
			printf("숫자를 입력하세요 : ");
			i++;
			scanf_s("%d", &Que);

			if (i == 5)
			{
				printf("남은 기회를 모두 소진하셨습니다. 실패!");
				Sleep(2000);
				running = 0;
				break; // 모든 기회 소진 시 UP,DOWN 문구가 나타나지 않게함
			}

			if (Que < Ans)
				printf("=== U  P ! ===\n");
			else if (Que > Ans)
				printf("=== DOWN ! ===\n");
			else if (Que == Ans)
			{
				printf("\n============\n\n정답입니다!!\n\n============");
				running = 0;
			}

		}
		break;

	case 2:
		for (int i = 0; i < 3; i++)
		{
			printf("AI가 1~100 사이의 숫자를 선택중입니다..\n");
			Sleep(330);
			system("cls");
			printf("AI가 1~100 사이의 숫자를 선택중입니다...\n");
			Sleep(330);
			system("cls");
			printf("AI가 1~100 사이의 숫자를 선택중입니다.\n");
			Sleep(330);
			system("cls");
		}
		srand(time(NULL));
		Ans = rand() % 100 + 1;

		// event_loop
		while (running)
		{
			printf("남은 기회 %d번\n", 5 - i);
			printf("숫자를 입력하세요 : ");
			i++;
			scanf_s("%d", &Que);

			if (i == 5)
			{
				printf("남은 기회를 모두 소진하셨습니다. 실패!");
				Sleep(2000);
				running = 0;
				break;
			}

			if (Que < Ans)
				printf("=== U  P ! ===\n");
			else if (Que > Ans)
				printf("=== DOWN ! ===\n");
			else if (Que == Ans)
			{
				printf("\n============\n\n정답입니다!!\n\n============");
				running = 0;
			}
		}
		break;

	default:
		break;
	}

	return 0;
}