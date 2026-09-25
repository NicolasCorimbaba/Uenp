from django.contrib import admin
from .models import Produto, Marca,Categoria

admin.site.register(Marca)
admin.site.register(Categoria)



@admin.register(Produto)
class ProdutoAdmin(admin.ModelAdmin):
    list_display = ('nome', 'preco', 'quantidade_estoque')