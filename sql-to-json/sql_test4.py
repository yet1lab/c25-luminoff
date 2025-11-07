import sqlite3

conn = sqlite3.connect("db.sqlite3")

cursor = conn.cursor()

x = '20:10:00'

sql = f"SELECT ((SELECT turma_id FROM core_horarioturma WHERE hora_fim IN ('{x}')) = (SELECT turma_id FROM core_horarioturma WHERE hora_inicio IN ('{x}')));"

cursor.execute(sql)



#  ('core_disciplina',), ('core_semestre',), ('core_horarioturma',), ('core_professor',), ('core_turma',), ('core_sala',)]

dados = cursor.fetchall()

print(dados)

conn.close()