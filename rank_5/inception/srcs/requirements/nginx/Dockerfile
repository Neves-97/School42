FROM debian:oldstable

RUN apt-get update && apt-get upgrade -y && apt-get install -y procps curl nginx openssl 


RUN mkdir -p /etc/nginx/ssl

#It creates a directory for SSL certificates and generates a self-signed certificate.

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=PT/ST=Lisboa/L=Lisboa/O=42/OU=42/CN=roda-min.42.fr"

#It creates a directory for WordPress and assigns proper permissions

RUN mkdir -p /var/www/wordpress && chown -R www-data:www-data /var/www/wordpress

#Finally, it tells Docker to run Nginx in the foreground when the container starts.
COPY conf/nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]
