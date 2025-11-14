FROM debian:oldstable

RUN apt-get update && apt-get upgrade -y && apt-get install -y curl php php7.4-fpm php-mysql mariadb-client netcat

#copies script into the container

COPY conf/wordpress_config.sh /

#makes it executable

RUN chmod +x ./wordpress_config.sh

#runs the script when the container starts

ENTRYPOINT [ "./wordpress_config.sh" ]
