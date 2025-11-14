FROM debian:oldstable

RUN apt-get update && apt-get upgrade -y && apt-get install -y mariadb-server net-tools procps

#copies script into the container
COPY ./conf/mariadb_config.sh /mariadb_config.sh 

#makes it executable
RUN chmod +x mariadb_config.sh

#runs the script when the container starts
ENTRYPOINT [ "./mariadb_config.sh" ]
