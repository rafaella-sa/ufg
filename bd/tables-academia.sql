CREATE TABLE Aluno (
    id_aluno integer not null,
    nome character varying(15) not null,
    sobrenome character varying(15) not null,
    data_de_inicio date not null,
    rua character varying(30),
    numero integer not null,
    bairro character varying(20),
    cidade character varying(20),
    email character varying(40),
    
    primary key (id_aluno)
);

CREATE TABLE A_Telefone (
    id_aluno integer not null,
    numero integer not null,
    primary key (id_aluno)
    
);

CREATE TABLE Departamento (
    
    id_dep integer not null,
    nome character varying(15),
    sala integer not null,
    primary key (id_dep)
);

CREATE TABLE Modalidade (
    mid integer not null,
    nome character varying(15),
    id_dep integer not null,

    primary key (mid),
    foreign key (id_dep) references Departamento(id_dep)

);

CREATE TABLE Professor (
    id_prof integer not null,
    nome character varying(15) not null,
    sobrenome character varying(15) not null,
    rua character varying(30),
    numero integer not null,
    bairro character varying(20),
    cidade character varying(20),
    email character varying(40),
    salario numeric(10,2),
    primary key (id_prof)
);

CREATE TABLE Turma (
    id_turma integer not null,
    turno character(1),
    id_prof integer not null,
    mid integer not null,
    
    primary key (id_turma),
    foreign key (id_prof) references Professor(id_prof),
    foreign key (mid) references Modalidade(mid)

);

CREATE TABLE Alunos_Turma (
    id_aluno integer not null references Aluno(id_aluno),
    nome character varying(15) not null,
    sobrenome character varying(15) not null,
    data_de_inicio date not null,
    rua character varying(30),
    numero integer not null,
    bairro character varying(20),
    cidade character varying(20),
    email character varying(40),    
    id_turma integer not null references Turma(id_turma),
    turno character(1),
    id_prof integer not null,
    mid integer not null,

    primary key (id_aluno,id_turma),
    foreign key (id_prof) references Professor(id_prof),
    foreign key (mid) references Modalidade(mid)

);



CREATE TABLE P_Telefone (
    id_prof integer not null,
    numero integer not null,
    primary key (id_prof)
);


