import os
import sys
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse


EXTENSIONS = {".jpg", ".jpeg", ".png", ".gif", ".bmp"}


def get_extension(url):
    url = url.split("?")[0].split("#")[0]
    return os.path.splitext(url)[1].lower()


def download_image(image_url, output_dir):
    extension = get_extension(image_url)

    if extension not in EXTENSIONS:
        return

    try:
        response = requests.get(image_url, timeout=10)
        response.raise_for_status()

        filename = os.path.basename(urlparse(image_url).path)

        if not filename:
            return

        os.makedirs(output_dir, exist_ok=True)

        filepath = os.path.join(output_dir, filename)

        if os.path.exists(filepath):
            return

        with open(filepath, "wb") as file:
            file.write(response.content)

        print(f"Downloaded: {image_url}")

    except requests.RequestException as error:
        print(f"Error downloading {image_url}: {error}")


def get_images(url, soup, output_dir):
    for image in soup.find_all("img"):
        src = image.get("src")

        if not src:
            continue

        image_url = urljoin(url, src)
        download_image(image_url, output_dir)


def get_links(url, soup, domain):
    links = []

    for link in soup.find_all("a"):
        href = link.get("href")

        if not href:
            continue

        full_url = urljoin(url, href)
        parsed = urlparse(full_url)

        if parsed.scheme not in ("http", "https"):
            continue

        if parsed.netloc != domain:
            continue

        if get_extension(parsed.path) not in ("", ".html", ".htm"):
            continue

        links.append(full_url)

    return links


def crawl(url, depth, max_depth, output_dir, visited, domain):
    if depth > max_depth:
        return

    if url in visited:
        return

    visited.add(url)

    print(f"Visiting: {url}")

    try:
        response = requests.get(url, timeout=10)
        response.raise_for_status()
    except requests.RequestException as error:
        print(f"Error visiting {url}: {error}")
        return

    content_type = response.headers.get("Content-Type", "")

    if "text/html" not in content_type:
        return

    soup = BeautifulSoup(response.text, "html.parser")

    get_images(url, soup, output_dir)

    if depth == max_depth:
        return

    for link in get_links(url, soup, domain):
        crawl(link, depth + 1, max_depth, output_dir, visited, domain)


def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} [-r] [-l N] [-p PATH] URL")
        return

    recursive = False
    max_depth = 5
    output_dir = "./data"
    url = None
    depth_specified = False

    i = 1

    while i < len(sys.argv):
        arg = sys.argv[i]

        if arg == "-r":
            recursive = True
            i += 1

        elif arg == "-l":
            if i + 1 >= len(sys.argv):
                print("Error: -l requires a number")
                return

            try:
                max_depth = int(sys.argv[i + 1])
            except ValueError:
                print("Error: -l requires a number")
                return

            if max_depth < 0:
                print("Error: depth must be >= 0")
                return

            depth_specified = True
            i += 2

        elif arg == "-p":
            if i + 1 >= len(sys.argv):
                print("Error: -p requires a path")
                return

            output_dir = sys.argv[i + 1]
            i += 2

        elif arg.startswith("-"):
            print(f"Error: unknown option {arg}")
            return

        else:
            if url is not None:
                print("Error: multiple URLs provided")
                return

            url = arg
            i += 1

    if url is None:
        print(f"Usage: {sys.argv[0]} [-r] [-l N] [-p PATH] URL")
        return

    if depth_specified and not recursive:
        print("Error: -l can only be used with -r")
        return

    domain = urlparse(url).netloc
    visited = set()

    if recursive:
        crawl(url, 0, max_depth, output_dir, visited, domain)
    else:
        crawl(url, 0, 0, output_dir, visited, domain)


if __name__ == "__main__":
    main()