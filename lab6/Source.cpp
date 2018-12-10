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

/*
__asm {

		push ebx
		push ecx
		push eax
		push edx

		//ecx is now pointing to the end of the string
		mov ebx, [numberOfDigits]
		sub ebx, 2

		mov ecx, skaicius
		add ecx, ebx

		mov edx, 0
		movsx bl, ebx
		mov ebx, 1
		inc bl

		for_loop:

			//eax yra dabartinis stringo charas
			mov al, byte ptr[ecx]
			movzx eax, al
			sub eax, 48

			//edx yra atsakymas
			imul eax, ebx
			add edx, eax

			//imul ebx, 10
			dec ecx
			//cmp bl, 0
			jnz for_loop

		mov [atsakymas], edx

		push edx
		push eax
		push ecx
		push ebx
	}
*/