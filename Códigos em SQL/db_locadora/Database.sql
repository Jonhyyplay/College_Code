CREATE TABLE Endereco (
    id_Endereco INT AUTO_INCREMENT PRIMARY KEY,
    rua VARCHAR(100) NOT NULL,
    numero VARCHAR(3),
    complemento VARCHAR(50),
    bairro VARCHAR(50) NOT NULL,
    cidade VARCHAR(50) NOT NULL,
    estado CHAR(2) NOT NULL,  
    CEP VARCHAR(9) NOT NULL
);

CREATE TABLE Cliente (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cpf VARCHAR(14) NOT NULL UNIQUE,
    telefone VARCHAR(15),
    email VARCHAR(100),
    id_Endereco INT, 
    FOREIGN KEY (id_Endereco) REFERENCES Endereco(id_Endereco)
);

CREATE TABLE Veiculo ( 
    id INT AUTO_INCREMENT PRIMARY KEY,
    marca VARCHAR(25) NOT NULL,
    modelo VARCHAR(25) NOT NULL,
    ano YEAR NOT NULL,
    placa VARCHAR(8) NOT NULL UNIQUE,
    cor VARCHAR(25),
    disponivel BOOLEAN DEFAULT TRUE
);

CREATE TABLE Funcionario (
    id INT AUTO_INCREMENT PRIMARY KEY,
    cpf VARCHAR(14) NOT NULL UNIQUE,
    nome VARCHAR(100) NOT NULL,
    cargo VARCHAR(25),
    salario DECIMAL(10, 2)
);

CREATE TABLE Locacao (
    id INT AUTO_INCREMENT PRIMARY KEY,
    data_Inicio DATE NOT NULL,
    data_Termino DATE NOT NULL,
    valor DECIMAL(10, 2), 
    forma_Pagamento VARCHAR(50), 
    status VARCHAR(30), 
    id_Cliente INT NOT NULL, 
    id_Veiculo INT NOT NULL, 
    id_Funcionario INT NOT NULL, 
    FOREIGN KEY (id_Cliente) REFERENCES Cliente(id),
    FOREIGN KEY (id_Veiculo) REFERENCES Veiculo(id),
    FOREIGN KEY (id_Funcionario) REFERENCES Funcionario(id)
);

INSERT INTO Endereco (rua, numero, complemento, bairro, cidade, estado, CEP) VALUES
('Rua das Amoreiras', '10', NULL, 'Centro', 'Imperatriz', 'MA', '65900-100'),
('Avenida do Sol', '250', 'Apto 202', 'Vila Nova', 'Imperatriz', 'MA', '65901-200'),
('Travessa da Lua', '12', 'Casa A', 'Bacuri', 'Imperatriz', 'MA', '65902-300'),
('Rua do Comércio', '300', NULL, 'Nova Imperatriz', 'Imperatriz', 'MA', '65903-400'),
('Alameda dos Uirapurus', '11', 'Casa azul', 'Santa Inês', 'Imperatriz', 'MA', '65919-274');

INSERT INTO Cliente (nome, cpf, telefone, email, id_Endereco) VALUES
('Jonathan Junior', '111.111.111-11', '99982422609', 'jonathan.junior123@gmail.com', 1),
('Maria Joana', '222.222.222-22', '99977665544', 'maria.joana@email.com', 2),
('Carlos Drumond', '333.333.333-33', '99966554433', 'carlos.d@email.com', 3),
('Fernanda Torres', '444.444.444-44', '99955443322', 'fernanda.t@email.com', 4),
('Roberto Justo', '555.555.555-55', '99944332211', 'roberto.j@email.com', 5);

INSERT INTO Veiculo (marca, modelo, ano, placa, cor, disponivel) VALUES
('Honda', 'Civic Typer R', 2020, 'MVX-8Z24', 'Vermelho', FALSE),
('Fiat', 'Argo', 2024, 'BBB-2B22', 'Preto', TRUE),
('Hyundai', 'Creta', 2022, 'CCC-3C33', 'Cinza', TRUE),
('Volkswagen', 'Polo', 2023, 'DDD-4D44', 'Vermelho', TRUE),
('Toyota', 'Corolla Cross', 2024, 'EEE-5E55', 'Azul', TRUE);

INSERT INTO Funcionario (nome, cpf, cargo, salario) VALUES
('Larissa Manoela', '666.666.666-66', 'Atendente', 2300.00),
('Gustavo Lima', '777.777.777-77', 'Gerente', 4500.00),
('Patrícia Dias', '888.888.888-88', 'Atendente', 2400.50),
('Rafael Gomez', '999.999.999-99', 'Atendente', 2350.74),
('Sofia Dantas', '111.222.345-69', 'Supervisor', 3800.00);

INSERT INTO Locacao (id_Cliente, id_Veiculo, id_Funcionario, data_Inicio, data_Termino, valor, forma_Pagamento, status) VALUES
(1, 1, 1, '2025-05-28', '2026-05-27', 2745.00, 'Cartão de Crédito', 'Ativa'), 
(2, 3, 2, '2025-05-27', '2025-06-03', 1050.00, 'Pix', 'Ativa'), 
(3, 2, 3, '2025-05-25', '2025-05-27', 180.00, 'Dinheiro', 'Finalizada'), 
(4, 5, 1, '2025-05-29', '2025-06-05', 1260.00, 'Débito', 'Ativa'),
(5, 4, 2, '2025-05-26', '2025-05-29', 330.00, 'Cartão de Crédito', 'Finalizada');