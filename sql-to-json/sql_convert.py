import sqlite3
import pandas as pd #

conn = sqlite3.connect("db.sqlite3")

cursor = conn.cursor()
# cursor.execute("SELECT name FROM sqlite_master WHERE type='table';")

cursor.execute(
"""
SELECT core_horarioturma.id, core_horarioturma.dia_semana, core_horarioturma.hora_inicio, core_horarioturma.hora_fim,
core_sala.nome as id_da_sala, core_horarioturma.turma_id FROM core_horarioturma left join
core_sala on core_horarioturma.sala_id = core_sala.id;
"""
)

# cursor.execute("SELECT * FROM core_disciplina;")


# cursor.execute("SELECT * FROM core_sala;")
'''
sql = "SELECT core_horarioturma.id, core_horarioturma.dia_semana, core_horarioturma.hora_inicio, core_horarioturma.hora_fim, core_sala.nome as id_da_sala, core_horarioturma.turma_id FROM core_horarioturma left join core_sala on core_horarioturma.sala_id = core_sala.id;"

df = pd.read_sql_query(sql, conn) #
'''
#################################    logica central      #######################################

# requisao = 46546546
# x = requisicao.hex()
# hora = ['18:30:00', '20:10:00', ... ]
# dia_semana = ['0','1','2','3','4']
# resultado = f'''select sala_id from core_horarioturma where hora_inicio = {hora} and dia_semana = {dia_semana} and
#  ((select turma_id from core_horarioturma where hora_inicio = {hora} and dia_semana = {dia_semana}) = (select turma_id from core_horarioturma where hora_fim = {hora}));'''
# return resultado

########################################################################

# tabelas = cursor.fetchall()

# print("Tabelas:", tabelas)
'''
print(df , "\n\n\n\n")

sql = "SELECT * FROM core_sala;"

df = pd.read_sql_query(sql, conn) #

print(df)
'''
# [('django_migrations',), ('sqlite_sequence',), ('auth_group_permissions',), ('auth_user_groups',), ('auth_user_user_permissions',),
#  ('django_admin_log',), ('django_content_type',), ('auth_permission',), ('auth_group',), ('auth_user',), ('django_session',),


#  ('core_disciplina',), ('core_semestre',), ('core_horarioturma',), ('core_professor',), ('core_turma',), ('core_sala',)]

dados = cursor.fetchall()

print(dados)

conn.close()

# hora,sala,desliga