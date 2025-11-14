#!/bin/bash

#wp cli command line wp

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar


chmod +x wp-cli.phar

mv wp-cli.phar /usr/local/bin/wp

cd /var/www/wordpress

#wordpress directiory permissions

chmod -R 755 /var/www/wordpress/

chown -R www-data:www-data /var/www/wordpress

#check if mariadb is active

connect_mariadb() {
    nc -z mariadb 3306   
    return $?
}

start=$(date +%s) 
end=$((start + 20)) 

#try connect maria db until respond or times up


while [ $(date +%s) -lt $end ]; do 
    connect_mariadb
    if [ $? -eq 0 ]; then 
        echo "[MARIADB UP AND RUNNING]"
        break 
    else  
        echo "[WAITING FOR MARIADB TO START]"
        sleep 1
    fi
done

#if fail

if [ $(date +%s) -ge $end ]; then
    echo "[MARIADB NOT RESPONDING]"
fi

#is wordpress installed

check_files() {
    wp core is-installed --allow-root > /dev/null
    return $?
}

if ! check_files; then
    echo "[WP INSTALLATION STARTED]"
    find /var/www/wordpress/ -mindepth 1 -delete
    wp core download --allow-root
    wp core config --dbhost=mariadb:3306 --dbname="$MYSQL_DB" --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" --allow-root
    wp core install --url="$DOMAIN_NAME" --title="$WP_TITLE" --admin_user="$WP_ADMIN_U" --admin_password="$WP_ADMIN_P" --admin_email="$WP_ADMIN_E" --allow-root
    wp user create "$WP_U_NAME" "$WP_U_EMAIL" --user_pass="$WP_U_PASS" --role=contributor --allow-root
else
    echo "[WordPress files already exist. Skipping installation]"
fi

# Modify the PHP-FPM configuration to use port 9000 instead of the socket
sed -i '36 s@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf

# Ensure the PHP socket directory exists

mkdir -p /run/php

# Start PHP-FPM in the foreground

/usr/sbin/php-fpm7.4 -F


