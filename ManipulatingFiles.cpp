#include <iostream>
#include <string>
#include <fstream>

auto ReadFile(std::string path) -> std::string {
	
	std::string fileContent; //Onde vai receber o que está escrito no arquivo

	std::ifstream archive; //Variavel para ler o arquivo

	archive.open(path); //Abre o arquivo no caminho especificado

	if (archive.is_open()) {

		std::getline(archive, fileContent); //Pega a primeira linha de texto do arquivo

		archive.close(); //Fecha o arquivo

		return fileContent;

	}
	else {

		fileContent = "Erro ao ler o arquivo!";

		return fileContent;

	}

}

auto WriteFile(std::string path, std::string contentToWrite) -> std::string {

	std::ofstream archive; //Variavel para escrever no arquivo

	archive.open(path);

	if (archive.is_open()) {

		archive << contentToWrite; //Insere a variavel no arquivo (isso perde todas as informações do arquivo)

		archive.close();

		return "Sucesso ao escrever no arquivo!";

	}
	else {

		return "Falha ao escrever no arquivo!";

	}

}

auto main() -> int {

	std::cout << WriteFile("Archive\\File.txt", "Escrevendo conteudo no arquivo de texto!") << std::endl;

	std::cout << ReadFile("Archive\\File.txt") << std::endl;

	std::cin.get();

}