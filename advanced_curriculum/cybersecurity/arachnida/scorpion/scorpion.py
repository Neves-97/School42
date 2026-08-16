import sys
from PIL import Image
from PIL.ExifTags import TAGS


SUPPORTED_EXTENSIONS = {
    ".jpg",
    ".jpeg",
    ".png",
    ".gif",
    ".bmp"
}


def get_extension(filename):
    filename = filename.lower()
    return filename[filename.rfind("."):] if "." in filename else ""


def print_metadata(filename):
    extension = get_extension(filename)

    if extension not in SUPPORTED_EXTENSIONS:
        print(f"Error: unsupported file type: {filename}")
        return

    try:
        image = Image.open(filename)

        print(f"File: {filename}")
        print(f"Format: {image.format}")
        print(f"Size: {image.size}")

        exif_data = image.getexif()

        if not exif_data:
            print("Creation date: Not available")
            print("EXIF: No EXIF metadata found.")
            print()
            return

        creation_date = None

        print("EXIF:")

        for tag_id, value in exif_data.items():
            tag = TAGS.get(tag_id, tag_id)

            print(f"  {tag}: {value}")

            if tag in ("DateTimeOriginal", "DateTimeDigitized", "DateTime"):
                if creation_date is None:
                    creation_date = value

        if creation_date:
            print(f"Creation date: {creation_date}")
        else:
            print("Creation date: Not available")

        print()

    except FileNotFoundError:
        print(f"Error: file not found: {filename}")
    except Exception as error:
        print(f"Error reading {filename}: {error}")


def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} FILE1 [FILE2 ...]")
        return

    for filename in sys.argv[1:]:
        print_metadata(filename)


if __name__ == "__main__":
    main()