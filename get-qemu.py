import requests
import re
import os

def download_file(url, filename):
    response = requests.get(url, stream=True)
    total_length = response.headers.get('content-length')
    if total_length is None:
        raise Exception("Unable to get file size.")
    total_length = int(total_length)

    with open(filename, "wb") as f:
        dl = 0
        for data in response.iter_content(chunk_size=4096):
            dl += len(data)
            f.write(data)
            done = int(50 * dl / total_length)
            print("\r[%s%s] %d%%" % ('=' * done, ' ' * (50-done), 100 * dl / total_length), end="")

def find_and_download_newest_tar_xz():
    response = requests.get("https://download.qemu.org/")
    content = response.text
    newest_version = None
    newest_url = None

    for line in content.split("\n"):
        match = re.search("qemu-([\d\.]+\.[0-9]+\.[0-9]+).tar.xz", line)
        if match:
            version = match.group(1)
            if newest_version is None or newest_version < version:
                newest_version = version
                newest_url = "https://download.qemu.org/qemu-" + newest_version + ".tar.xz"

    if newest_url is None:
        raise Exception("Unable to find newest tar.xz package.")

    try:
        download_file(newest_url, "qemu.tar.xz")
        print("\nDownload complete.")
    except Exception as e:
        os.remove("qemu.tar.xz")
        print("\nDownload failed:", e)

if __name__ == "__main__":
    find_and_download_newest_tar_xz()
