all: up

DCPATH = ./srcs/docker-compose.yml


up:
	docker-compose -f $(DCPATH) up --build


down:
	docker-compose -f $(DCPATH) down


clean:
	docker system prune -a --volumes -f
	docker volume rm mariadb wordpress


re:
	make down
	make up



