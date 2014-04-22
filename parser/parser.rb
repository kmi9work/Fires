# require 'net/http'
# require 'nokogiri'
# require 'iconv'

require 'nokogiri'
require 'open-uri'
require 'uri'

def get_links_sections url
  sleep(rand(10) + 2)
  while true
    begin
      doc = Nokogiri::HTML(open(url))
      break
    rescue
      puts "Error in open url. 1"
      sleep(rand(50) + 100)
    end
  end
  sections = []
  links = {}
  doc.css('table.countryMap a').each do |link|
    if link.content == ">>>"
      sections << 'http://rp5.ru' + link["href"]
      if links.key(sections.last)
        links.delete_if{|_, value| value == sections.last}
      end
    else
      links[link.content] = 'http://rp5.ru' + link["href"]
    end
  end
  sections.uniq!
  return [links, sections]
end
f_links = File.open "links_krasnoyarsk.txt", 'w+'
f_sections = File.open "sections_krasnoyarsk.txt", 'w+'

meteo_ids = {}
links, sections = *get_links_sections('http://rp5.ru/%D0%9F%D0%BE%D0%B3%D0%BE%D0%B4%D0%B0_%D0%B2_%D0%9A%D1%80%D0%B0%D1%81%D0%BD%D0%BE%D1%8F%D1%80%D1%81%D0%BA%D0%BE%D0%BC_%D0%BA%D1%80%D0%B0%D0%B5')

sections.each do |section|
  print "get links..."
  puts section
  l, s = *get_links_sections(URI::encode section)
  links.merge!(l)
  unless s.empty?
    s.each do |sect|
      ln, ss = *get_links_sections(URI::encode sect)
      links.merge!(ln)
    end
  end
end
# sleep(1)



f_links.puts links.inspect
puts "links collected"

links.each do |key, value|
  puts value
  f_ids = File.open('ids_krasnoyarsk.txt', 'a+')
  sleep(rand(10) + 2)
  while true
    begin
      doc = Nokogiri::HTML(open(URI::encode value))
      break
    rescue
      puts "Error in open url. 2"
      sleep(rand(50) + 100)
    end
  end
  puts archive_link = doc.at_css('#archive_link')['href']
  sleep(rand(10) + 2)
  while true
    begin
      doc = Nokogiri::HTML(open(URI::encode archive_link))
      break
    rescue
      puts "Error in open url. 3"
      sleep(rand(50) + 100)
    end
  end
  puts meteo_ids[key] = doc.at_css('div.archButton')['onclick'].match(/fconfirm\(\d+,(\d+)\)/)[1]
  coord = doc.at_xpath('//*[@id="content"]/script').content.match(/latitude=(\d+(\.\d+)?)&longitude=(\d+(\.\d+)?)&/)
  f_ids.puts "#{key} => #{meteo_ids[key]} | (#{coord[1]}, #{coord[3]})"
  f_ids.close
end


# content > script

# latitude=45.05&longitude=39.033333333333&


puts 



# All sections (>>>)

# puts page.scan(/<div class="RuLinks">.*<a href="(.+?)">/)#\s*<\/a>\s*,\s*<\/b>/)#.*<a style="color:#000" href="(.+?)"><span class="ToWeather">.*/)
