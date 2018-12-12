#include <iostream>
#include <Windows.h>

int main(int argc, char** argv) {

	char gaidis[] = "0123456";
	char* skaicius = gaidis;
	int numberOfDigits = sizeof(gaidis) / sizeof(char);
	numberOfDigits += -1;
	int atsakymas;
	char simbolis;

	__asm {

		push edx
		push eax
		push ebx
		push ecx
		push edi
		push esi

		mov ecx, [numberOfDigits]
		mov eax, skaicius
		mov edi, eax
		dec ecx
		add edi, ecx

		
		//eax yra dabartinis masyvo elementas
		//ecx yra masyvo elementu kiekis
		//edi yra masyvas
		//edx bus atsakymas

		mov ebx, 1
		xor edx, edx
		for_loop:

			mov al, byte ptr[edi]
			movzx eax, al
			sub eax, 48

			imul eax, ebx
			add edx, eax
			imul ebx, 10

			dec edi
			dec ecx
			jnz for_loop

		mov [atsakymas], edx

		pop esi
		pop edi
		pop ecx
		pop ebx
		pop eax
		pop edx
	}



	
	std::cout << atsakymas;
	std::cin.get();

	return 0;
}
/*
int answer = 0, factor = 1;
for (int i = str.length()-1; i >= 0; i--) {
	answer += (str.charAt(i) - '0') * factor;
	turi issiaugoti					  turi issisaugoti
	factor *= 10;
}
*/