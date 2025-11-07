import sqlite3
import pandas as pd #

conn = sqlite3.connect("db.sqlite3")

x = '20:10:00'

sql = f"SELECT ((SELECT * FROM core_horarioturma WHERE hora_fim IN ('{x}')) = (SELECT * FROM core_horarioturma WHERE hora_inicio IN ('{x}')));"

#  ('core_disciplina',), ('core_semestre',), ('core_horarioturma',), ('core_professor',), ('core_turma',), ('core_sala',)]

df = pd.read_sql_query(sql, conn) 

print(df)

conn.close()