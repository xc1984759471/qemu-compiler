#本脚本在chatgpt指导下完成(doge)
import argparse
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
        for data in response.iter_content(chunk_size=65536):
            dl += len(data)
            f.write(data)
            done = int(50 * dl / total_length)
            print("\r[%s%s] %d%%" % ('=' * done, ' ' * (50-done), 100 * dl / total_length), end="")

def find_and_download_newest_tar_xz(is_rc=False):
    url = "https://download.qemu.org/"
    if is_rc:
        url += "?C=M;O=D"

    response = requests.get(url)
    content = response.text
    newest_version = None
    newest_url = None

    for line in content.split("\n"):
        if is_rc:
            match = re.search(r"qemu-([\d\.]+\.[\d\.]+\.[\d\.]+-rc[\d\.]+).tar.xz", line)
        else:
            match = re.search(r"qemu-([\d\.]+\.[\d\.]+\.[\d\.]+).tar.xz", line)

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
    parser = argparse.ArgumentParser(description="Download the newest QEMU tar.xz package.")
    parser.add_argument("--rc", action="store_true", help="Include release candidate versions")
    args = parser.parse_args()

    find_and_download_newest_tar_xz(args.rc)
